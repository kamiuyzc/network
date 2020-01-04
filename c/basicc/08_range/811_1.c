#include <stdio.h>
int g;
int r;
int d = 10;
extern int s;
void fun1();

int main(void)
{
    int ij;
    printf("i = %d\n", ij); 
    printf("s = %d\n", s); 
	fun1();
	return 0;
}

int s = 20;
