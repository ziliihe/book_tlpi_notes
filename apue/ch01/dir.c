#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[] )
{
    DIR *dir;
    struct dirent* ent;

    if ( argc != 2 ) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    if ( ( dir = opendir(argv[1]) ) == NULL ) {
        printf("Error opening directory: %s\n", argv[1]);
        return 1;
    }

    printf("Files in directory: '%s'\n", argv[1]);
    while ( (ent = readdir(dir)) != NULL ) {
        printf("%s\n", ent->d_name);
    }
    closedir(dir);
    return 0;
}
