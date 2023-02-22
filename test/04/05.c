#include <unistd.h>
#include <stdio.h>

int main()
{
    char buffer[1024];
    ssize_t n;

    n = read(STDIN_FILENO, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }

    if (write(STDOUT_FILENO, buffer, n) < 0) {
        perror("write");
        return 1;
    }

    return 0;
}