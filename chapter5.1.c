#include <stdio.h>

int is_leap_year1(int year);
int is_leap_year2(int year);

int main(void)
{
    int i;
    for(i = 1000; i<2017; i++){
        printf("i:%d\t%d\t%d\n", i, is_leap_year1(i), is_leap_year2(i));
        if (is_leap_year1(i) != is_leap_year2(i)){
            printf("error\n");
            return 0;
        }
    }
    return 0;
}

int is_leap_year1(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    else if (year % 400 == 0)
        return 1;
    else
        return 0;
}

int is_leap_year2(int year)
{
    if (year % 400 != 0 && (year % 4 != 0 || year % 100 == 0))
        return 0;
    else
        return 1;
}
