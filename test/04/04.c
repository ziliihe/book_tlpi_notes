#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'b';
    if (isprint(ch)) {
        printf("'%c' is a printable character, %d\n", ch, isprint(ch));
    } else {
        printf("'%c' is not a printable character, %d\n", ch, isprint(ch));
    }
    return 0;
}
 