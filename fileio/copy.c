#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE  /* 允许 cc -d 覆盖定义 */
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[])
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    /* cp arg1 arg2 or cp --help */
    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        errExit("opening file %s", argv[1]);
    
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR  | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;   /* rw-rw-rw- */
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1)
        errExit("opening file %s", argv[2]);
    
    /* 数据传输，直到输入终止，或出现错误 */
    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0) {
        if (write(outputFd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer");
    
    if (numRead = -1)
        errExit("read");
    
    if (close(inputFd) == -1)
        errExit("close input");
    
    if (close(outputFd) == -1)
        errExit("close output");

    
    exit(EXIT_SUCCESS);
            
    }

        
}