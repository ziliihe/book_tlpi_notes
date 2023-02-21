#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_READ 200
char buffer[MAX_READ];

int main()
{
    int fd = open("t3.c", O_RDONLY);
    int re = read(fd, buffer, MAX_READ);
    printf("fd %d, re %d, errno %d\n", fd, re, errno);

    printf("The input data was: %s\n", buffer);
    return 0;
}
   