#include <stdio.h>
#include <math.h>

double myround(double x);

int main(void)
{
    double i;
    //printf("%f %f %f %f",ceil(-4.5), floor(-4.5), ceil(4.5), floor(4.5));
    for(i = -2.0; i < 2; i += 0.1)
        printf("i:%f\tround:%f\n", i, myround(i));
}

double myround(double x)
{
    if ((x - floor(x)) < 0.5)
        return floor(x);
    else
        return ceil(x);
}
