#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int main()
{
    int fd1;
    int fd2;
    char *str;

    int i = 25;

    while(i > 0)
    {
        fd2 = open("burak.txt", O_RDWR, 0777);
        int j = 0;
        while(j < i)
        {
            str = get_next_line(fd2);
            j++;
        }
        printf("%s",str);
        i--;
        free(str);
        close(fd2);
    }
return(0);
}