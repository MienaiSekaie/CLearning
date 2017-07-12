#include <stdio.h>

int main(void)
{
    double i = 20.0;
    double j = i / 7.0;
    while(j * 7.0 == i)
    {
        printf("Equal. %f\n", i);
        i = i + 1;
        j = i / 7.0;
    }
    printf("Unequal. %f\n", i);
    return 0;
}
