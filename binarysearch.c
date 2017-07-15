#include <stdio.h>

#define LEN 8
int a[LEN] = {1, 2, 2, 2, 5, 6, 8, 9};

int binary_search(int number)
{
    int mid, start = 0, end = LEN - 1, i;

    while (start <= end){
        mid = (start + end) / 2;
        if (a[mid] < number)
            start = mid + 1;
        else if (a[mid] > number)
            end = mid - 1;
        else{
            for(i = mid - 1; a[i] == a[mid]; i--)
                mid--;
            return mid;
        }
    }
    return -1;
}

double mysqrt(double y)
{
    double d_sqrt = 0, min = 0, max = y;
    while ((d_sqrt * d_sqrt - y) < -0.001 || (d_sqrt * d_sqrt - y) > 0.001){
        d_sqrt = (min + max) / 2;
        if (d_sqrt * d_sqrt < y)
            min = d_sqrt;
        else
            max = d_sqrt;
    }
    return d_sqrt;
}

double mypow(double x, int n)
{
    if (n == 1)
        return x;
    else
        return mypow(x, n / 2) * mypow(x, n - n / 2);
}

int main(void)
{
    printf("%f\n", mypow(2.0, 3));
    return 0;
}
