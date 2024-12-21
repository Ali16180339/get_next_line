#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int  i = open("asd.txt",O_RDONLY);

	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));
    printf("%s", get_next_line(i));
}