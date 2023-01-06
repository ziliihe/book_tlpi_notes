#include <stdarg.h>
#include <stdio.h>
void foo(char *fmt, ...)
{
    va_list ap;
    int d;
    char c;
    char *s;

    va_start(ap, fmt);
    while(*fmt)
    {
        switch(*fmt++)
        {
            case 's':
            {
                s = va_arg(ap, char *);
                printf("string %s\n", s);
                break;
            }
            case 'd':
            {
                d = va_arg(ap, int);
                printf("int %d\n", d);
                break;
            }
            case 'c':
            {
                c = (char)va_arg(ap, int);
                printf("char %c\n", c);
                break;
            }
        }
    }
    va_end(ap);
}

int main()
{
      /* 这里csds指定的是后面的4个参数格式，你大爷的呢 */
      foo("csds", 'b', "of", 50, "you");
      return 0;
}