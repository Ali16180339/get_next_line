/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:09:59 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/22 17:38:54 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;

	i = 0;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if(!s)
		return (NULL);
	
	while (*s)
	{
		if (*s == (char)(c))
			return ((char *)(s));
		s++;
	}

	if (c == '\0')
		return (char *)s;
	
	return NULL;
}
