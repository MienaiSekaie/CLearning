#include <stdio.h>
#include <math.h>

void diamond(int, char);
int is_even(int);
void print_d(int, int, char);

int main(void)
{
    diamond(3, '*');
    diamond(5, '+');
}

void diamond(int n, char c)
{
    int i;
    if (is_even(n))
        printf("please input a odd!");
    else{
        for (i = 0; i < ceil(n/2.0); i++){
            print_d(2 * i + 1, n, c);
        }
        for (--i ; i > 0; i--){
            print_d(2 * i - 1, n, c);
        }
    }
}

void print_d(int i, int n, char c)
{
    int j;
    for (j = 0; j < (n - i) / 2; j++)
        printf("   ");
    for (j = 0; j < i; j++)
        printf("%3c", c);
    printf("\n");
}

int is_even(int n)
{
    return !(n % 2);
}
