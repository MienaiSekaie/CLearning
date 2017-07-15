#include <stdio.h>

char a[] = "hello world";

int indexof(char letter)
{
    int i = 0;
    for (; a[i] != '\0'; i++)
        if (a[i] == letter)
            return i;
    return -1;
}

int main(void)
{
    printf("%d %d\n", indexof('o'), indexof('z'));
    return 0;
}
