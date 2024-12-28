#include "get_next_line.h"
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
    str = get_next_line(fd);
    printf("%s", str);
    free(str);

    close(fd);
}