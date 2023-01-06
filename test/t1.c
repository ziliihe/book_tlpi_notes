#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int f(int n, ...)
{
    va_list argList;
    double average = 0.0;
    int sum = 0;
    
    va_start(argList, n);
    int i;
    for (i=0;i < n; i++) {
        sum += va_arg(argList, int);
    }
    va_end(argList);
    return (double) sum / n;
}

void f2(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    char * s;
    int d;
    while (*fmt) {
        printf("fmt -> %c\n", *fmt);
        switch(*fmt++) {
            case 's':
            {
                s = va_arg(ap, char *);
                printf("string : %s\n", s);
                break;
            }
            case 'd':
            {
                d = va_arg(ap, int);
                printf("decimal: %d\n", d);
                break;
            }
        }
    }
    va_end(ap);
}

int main(){
    printf("result = %d\n", f(5, 1, 2, 3, 4, 5));
    f2("zhang", "hui", "he", 1218, "he");
    exit(EXIT_SUCCESS);
}