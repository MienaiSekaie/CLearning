#include <stdio.h>
#include <math.h>

struct rational make_rational(int, int);
struct rational add_rational(struct rational, struct rational);
struct rational sub_rational(struct rational, struct rational);
struct rational mul_rational(struct rational, struct rational);
struct rational div_rational(struct rational, struct rational);
void print_rational(struct rational);
int gcd(int a, int b);
int abs(int);

struct rational {
    int x, y;
};

int main(void)
{
    struct rational a = make_rational(1, 8);
    struct rational b = make_rational(-1, 8);
    print_rational(add_rational(a, b));
    print_rational(sub_rational(a, b));
    print_rational(mul_rational(a, b));
    print_rational(div_rational(a, b));

    return 0;
}

int abs_int(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
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

struct rational make_rational(int x, int y)
{
    int rat_gcd;
    struct rational z;
    if (y == 0){
        printf("The number is invalid!");
        z.x = z.y = 0;
    }else if (x == 0){
        z.x = 0;
        z.y = 1;
    }else{
    rat_gcd = gcd(abs_int(x), abs_int(y));
    x = x / rat_gcd;
    y = y / rat_gcd;
    }
    if (y < 0){
        z.x = -x;
        z.y = -y;
    }else{
        z.x = x;
        z.y = y;
    }
    return z;
}

struct rational add_rational(struct rational a, struct rational b)
{
    return make_rational(a.x * b.y + a.y * b.x, a.y * b.y);
}

struct rational sub_rational(struct rational a, struct rational b)
{
    return make_rational(a.x * b.y - a.y * b.x, a.y * b.y);
}

struct rational mul_rational(struct rational a, struct rational b)
{
    return make_rational(a.x * b.x, a.y * b.y);
}

struct rational div_rational(struct rational a, struct rational b)
{
    return make_rational(a.x * b.y, a.y * b.x);
}

void print_rational(struct rational a)
{
    if (a.y == 0)
        printf("infinite number\n");
    else if (a.x == 0)
        printf("0\n");
    else if (a.y == 1)
        printf("%d\n", a.x);
    else
        printf("%d/%d\n", a.x, a.y);
}
