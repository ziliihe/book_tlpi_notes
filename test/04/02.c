#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);  // 打开文件

    int flags = fcntl(fd, F_GETFL, 0);  // 获取文件描述符标志
    printf("current flags = %d\n", flags);
    flags |= O_APPEND;                  // 设置 O_APPEND 标志
    fcntl(fd, F_SETFL, flags);          // 设置文件描述符标志

    write(fd, "hello, world\n", 13);    // 写入文件

    close(fd);                          // 关闭文件

    return 0;
}
