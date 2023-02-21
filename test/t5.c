#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 40

char buffer[BUF_SIZE+1];

int main()
{
    buffer[0] = 'h';
    buffer[1] = 'e';
    buffer[2] = 'h';
    buffer[3] = 'u';
    buffer[4] = 'i';
    buffer[5] = '\n';
    buffer[6] = '\0';

    int outputFd = open("hello.txt", O_WRONLY | O_APPEND);
    int wr = write(outputFd, buffer, BUF_SIZE);


    return 0;
}