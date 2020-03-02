#include <stdio.h>
extern int s;
void fun1()
{
    printf("extern global fun1 %d\n", s);
}

