/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:08:53 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/29 17:34:25 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = b;
	i = 0;
	while (i < len)
		*(ptr + i++) = c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	if (ptr != NULL)
		ft_memset(ptr, 0, count * size);
	return (ptr);
}

char	*ft_read(int fd, char *leftover)
{
	char	*read_buf;
	int		byte;
	char	*tmp;

	byte = 1;
	read_buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!leftover)
		leftover = ft_strdup("");
	while (ft_strchr(read_buf, '\n') == 0 && byte > 0)
	{
		byte = read(fd, read_buf, BUFFER_SIZE);
		if ((byte == -1) || (byte == 0 && !leftover[0]))
		{
			free(read_buf);
			free(leftover);
			return (NULL);
		}
		read_buf[byte] = '\0';
		tmp = leftover;
		leftover = ft_strjoin(leftover, read_buf);
		free(tmp);
	}
	free(read_buf);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*read_line;
	int			j;
	char		*temp;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = NULL;
	leftover = ft_read(fd, leftover);
	j = 0;
	while (leftover && leftover[j])
	{
		if (leftover[j] == '\n' || leftover[j + 1] == '\0')
		{
			j++;
			read_line = ft_substr(leftover, 0, j);
			temp = leftover;
			leftover = ft_strdup(leftover + j);
			free(temp);
			return (read_line);
		}
		j++;
	}
	return (read_line);
}
