#include <stdio.h>
#include <head.h>
// int add(int x, int y);
// int sub(int x, int y);

int main(void)
{
    int a, b, sum, r;
    a = 60;
    b = 20;
    sum = add(a, b);
    r = sub(a, b);
    printf("result is :%d\n", sum);
    printf("result is :%d\n", r);
    return 0;
}

