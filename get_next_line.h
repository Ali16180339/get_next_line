/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:02:23 by agokcek           #+#    #+#             */
/*   Updated: 2024/12/22 20:03:29 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char    *get_next_line(int fd);
int     ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);

#endif