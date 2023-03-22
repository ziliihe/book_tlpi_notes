#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main( int argc, char* argv[] ) {
    if ( argc != 3 ) {
        fprintf( stderr, "Usage: %s source_fiel target_file\n", argv[0]);
        exit( EXIT_FAILURE );
    }

    int source_fd = 0;
    int target_fd = 0;

    struct stat st;
    off_t offset = 0;

    /* open source file */
    source_fd = open( argv[1], O_RDONLY );
    if (source_fd == -1 ) {
        perror( "Open source file");
        exit( EXIT_FAILURE );
    }

    if ( fstat( source_fd, &st ) == -1 ) {
        perror("fstat source file");
        exit( EXIT_FAILURE );
    }

    target_fd = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode );
    if (target_fd == -1 ) {
        perror("create target file");
        exit( EXIT_FAILURE );
    }

    char buffer[1024];
    ssize_t nread = 0, nwrite = 0;
    while (( nread = read( source_fd, buffer, sizeof( buffer ))) > 0) {
        off_t hole_offset = lseek( source_fd, 0, SEEK_CUR );
        off_t hole_size   = hole_offset - offset - nread;

        if ( hole_size > 0) {
            if (lseek( target_fd, hole_size, SEEK_CUR) == -1 ) {
                perror("lseek target file");
                exit( EXIT_FAILURE );
            }
        }

        nwrite = write(target_fd, buffer, nread );
        if ( nwrite == -1 ) {
            perror("write targe file");
            exit( EXIT_FAILURE);
        }

        offset += nread;
    }

    if ( close( source_fd ) == -1 ) {
        perror("close source file");
        exit(EXIT_FAILURE);
    }
    if ( close( target_fd ) == -1 ) {
        perror("close target file");
        exit(EXIT_FAILURE);
    }

    return 0;
}