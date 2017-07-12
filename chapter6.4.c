#include <stdio.h>
#include <math.h>

int is_prime(int);

int main(void)
{
    int i;
    for(i = 1; i <= 100; i++){
        if(is_prime(i))
            printf("%d\n", i);
    }
    return 0;
}

int is_prime(int n)
{
    int i;
    if (n < 2)
        return 0;
    for (i = 2; i <= floor(sqrt(n)); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
