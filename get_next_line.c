#include "get_next_line.h"
#include <stdio.h>


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

char *ft_read(int fd, char *leftover)
{
    char *read_buf;
    int flag;
    int byte;

    flag = 0;
    read_buf = malloc(BUFFER_SIZE + 1);
    if (!leftover)
        leftover = malloc(1);
    if (!read_buf)
        return (NULL);
    while (flag != 1)
    {
        byte=read(fd, read_buf, BUFFER_SIZE);
        if (ft_strchr(read_buf, '\n') || byte==0)
            flag = 1;
        read_buf[byte]='\0';
        leftover = ft_strjoin(leftover, read_buf);
    }

    return (leftover);
}

char *get_next_line(int fd)
{
    static char *leftover;
    char *read_line;
    int j;
    char *temp;

    leftover = ft_read(fd, leftover);

    j = 0;
    while (leftover && leftover[j])
    {
        if (leftover[j] == '\n' || leftover[j+1] == '\0')
        {
            j++;
            read_line = ft_substr(leftover, 0, j);
            temp = leftover;
            leftover = ft_strdup(leftover + j);
            free(temp);
        }
        j++;
    }
    return (read_line);
}


#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *str;
    fd = open("Mustafam.txt", O_RDWR, 0777);

    str = get_next_line(fd);
    printf("%s", str);
    free(str);

    str = get_next_line(fd);
    printf("%s", str);
    free(str);

    str = get_next_line(fd);
    printf("%s", str);
    free(str);

     str = get_next_line(fd);
    printf("%s", str);
    free(str);

}