 #include <stdio.h>
 #include <stdlib.h>
 #include <getopt.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>


#define MAX_BUF_SIZE 1024

 int main( int argc, char* argv[] ) {
    /* get opt */
    int opt = 0;
    int append = 0;
    while ( ( opt = getopt( argc, argv, "a")) != -1 ) {
        switch ( opt ) {
            case 'a':
                append = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s [-a] file\n", argv[0] );
                exit( EXIT_FAILURE );
        }
    }

    if ( optind >= argc ) {
        fprintf( stderr, "Usage: %s [-a] file\n", argv[0]);
        exit( EXIT_FAILURE );
    }

    int fd = 0;
    char buf[MAX_BUF_SIZE];
    /* there is a -a option, then has O_APPEND authority */
    if ( append ) {
        fd = open( argv[optind], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR ); 
    } else {
        fd = open( argv[optind], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR ); 
    }

    if ( fd == -1 ) {
        fprintf( stderr, "Error opening file: %s\n", argv[optind]);
        exit( EXIT_FAILURE );
    }

    ssize_t n = 0;
    while ( ( n = read( STDIN_FILENO, buf, MAX_BUF_SIZE )) > 0 ) {
        if ( write( STDOUT_FILENO, buf, n ) != n ) {
            fprintf( stderr, "Error writing to standard output\n");
            exit( EXIT_FAILURE );
        }

        if ( write( fd, buf, n ) != n ) {
            fprintf( stderr, "Error writing to standard output\n");
            exit( EXIT_FAILURE );
        }
    }
    close( fd );
    return 0;
}