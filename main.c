#include <stdio.h>

/* main: generate some simple output*/
int ceiling(int x, int y);
int increment(int x);

int main(void)
{
    int x1=17, x2=16, n=4;
    printf("%d %d\n",ceiling(x1, n), ceiling(x2, n));
    printf("Hello, world.\n");
    printf("Character: %c\ninteger: %d\nfloating point: %f\n%%", '}', 34, 3.14);
    printf("%d + 1 = %d", n, increment(n));
    return 0;
}

int ceiling(int x, int y)
{
    if (x % y > 0)
        return x / y + 1;
    else
        return x / y;
}

int increment(int x)
{
    return x + 1;
}
