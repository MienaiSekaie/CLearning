#include <stdio.h>

int gcd(int, int);
int fibonacci(int);
int gcd_iter(int, int);
int fibonacci_iter(int);

int main(void)
{
    printf("%d %d\n", gcd(64, 96), fibonacci(10));
    printf("%d %d\n", gcd_iter(64, 96), fibonacci_iter(10));
    return 0;
}

int gcd(int a, int b)
{
    if (a <= 0 || b <= 0){
        printf("please input a positive number");
        return 0;
    }
    else if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int gcd_iter(int a, int b)
{
    int temp;
    if (a <= 0 || b <= 0){
        printf("please input a positive number");
        return 0;
    }
    while (a % b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int fibonacci(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else if(n > 1)
        return fibonacci(n - 1) + fibonacci(n - 2);
    else{
        printf("please input a positive number");
        return -1;
    }
}

int fibonacci_iter(int n)
{
    int i, fib, fib1 = 1, fib2 = 1;
    if (n < 0){
        printf("please input a positive number");
        return -1;
    }else if(n == 0 || n == 1)
        return 1;
    else{
        for (i = 2; i <= n; i++){
            fib = fib1 + fib2;
            fib2 = fib1;
            fib1 = fib;
        }
        return fib;
    }
}
