/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:09:59 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/28 17:13:56 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len || len == 0)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[start])
	{
		if (j < len)
			str[j++] = s[start];
		start++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s);
	i = 0;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}