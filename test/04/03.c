#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("argment count = %d\n", argc);
    for (int i = 0; i < argc; i++) 
        printf("i = %d, para = %s\n", i, argv[i]);
    return 0;
}