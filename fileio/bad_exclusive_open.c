#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <tlpi_hdr.h>

/*
 *
 * ./bad_exclusive_open filename sleep &
 *
 */
int main(int argc, char* argv[]) {
    int fd = open( argv[1], O_EXCL );
    if ( fd != -1 ) {
        printf("[PID %ld] File \"%s\" already exist\n", (long)getpid(),  argv[1]);
        close( fd );
    } else {
        printf("[PID %ld] File \"%s\" doesn't exist yet, argc = %d\n", (long)getpid(),  argv[1], argc);
        if ( argc > 2 ) {
            printf("[PID %ld] start sleeping\n", (long) getpid());
            sleep( 5 );
            printf("[PID %ld] Done sleeping\n", (long) getpid());
        }
        if ( errno != ENOENT ) {
            errExit("open");
        } else {
            fd = open( argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR );
            if ( fd == -1 ) {
                err_exit("open");
            }

            printf("[PID %ld] Created file \"%s\" exclusively\n",  (long) getpid(), argv[1] );
        }
    }

    return 0;
}