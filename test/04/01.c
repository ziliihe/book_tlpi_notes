#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd1 = open("startup", O_RDONLY);
    printf("fd1 = %d\n", fd1);

    int fd2 = open("myfile", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    printf("myfile %d\n", fd2);

    int fd3 = open("w.log", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    printf("w.log = %d\n", fd3);

    return 0;
}