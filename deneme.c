#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

/* 
int main()
{
    int fd;
    char *line;

    fd = open("a.txt", O_RDONLY);
    if(fd < 0)
        return 0;
    line = get_next_line(fd);
    if(!line)
        return 0;
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);

    free(line);

    close(fd);
    return 0;
}
int main()
{
    char *line;
    int fd = open("a.txt", O_RDONLY);
    if (fd < 0)
        return 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    if (line==NULL)
    {
        printf("null döndü");
    }

    close(fd);
    return 0;
}

int main()
{
    char *line;
    char *lastline = NULL;
    int fd = open("a.txt", O_RDONLY);
    if (fd < 0)
        return 0;

    while (1)
    {
        line = get_next_line(fd);
        if (line)
        {
            free(lastline);
            lastline = malloc(ft_strlen(line) + 1);
            if (lastline)
            {
                int i = 0;
                while (line[i])
                {
                    lastline[i] = line[i];
                    i++;
                }
                lastline[i] = '\0';
            }
                free(line);
        }
        else
        {
            if (lastline)
                printf("%s", lastline);
            break;
        }
    }

    free(lastline);
    close(fd);
    return 0;
}


//TÜM DOSYAYI
int main()
{
    int fd;
    char *line;

    fd = open("test1.txt", O_RDONLY);
    if(fd < 0)
        return 0;
    while(1)
    {
        line = get_next_line(fd);
        if(!line)
        break;
            printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
//İLK SATIRI ALMA(REACHABLE KALI)
int main()
{
    int fd;
    char *line;

    fd = open("test1.txt", O_RDONLY);
    if(fd < 0)
        return 0;
    line = get_next_line(fd);
    if(!line)
        return 0;
    printf("%s", line);
    free(line);

    close(fd);
    return 0;
}
//ÇOKLU DOSYA OKUMA
int main()
{
    int fd1;
    int fd2;
    char *line1;
    char *line2;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    if(fd1 < 0 || fd2 < 0)
        return 0;
    while(1)
    {
        line1 = get_next_line(fd1);
        if(line1 != NULL)
        {
            printf("%s",line1);
            free(line1);
        }
        line2 = get_next_line(fd2);
        if(line2 != NULL)
        {
            printf("%s",line2);
            free(line2);
        }
        if(!line1 && !line2)
            break;
    }
    close(fd1);
    close(fd2);
    return 0;
}

*/