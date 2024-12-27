#include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

/* char *get_next_line(int fd)
{
    
}
*/

int main()
{
    char *s;
    char *str;
    char *line;
    int fd;
    int i;
    int j;
    char * n_position;
    
    i = 1;
    j = 0;
    fd = open("Mustafam.txt",O_RDWR, 0777);
    s = (char *)malloc(BUFFER_SIZE+1);
    str = malloc(1);
    line = malloc(1);

    while(i > 0)
    {
        i = read(fd,s,BUFFER_SIZE);
        s[i] = '\0';
        n_position= ft_strchr(s,'\n');
        if (!n_position)
        {
            // n position dahil olacak şekilde bir yere kopyala, bu senin return edeceğin line'ın
            // n positiondan sonraki kısım da remainder ın, bunu static variableda store etmen gerekiyor ki sonraki fonkisyon çağırılışında bunu da dahil etsin
        }
    
    }
    
    while(str[j] != '\n' || str[j] != '\0')
    {
        if (str[j]=='\n')
        {
            // \n i dahil etmek için burayı yazabilirsin
        }
        
        line[j] = str[j];
        j++;
    }

    // printf("%s\n",line);

    // str=str+j+1;
    // j=0;

    // while(str[j] != '\n')
    // {
    //     line[j] = str[j];
    //     j++;
    // }

    printf("%s\n",str);



}
