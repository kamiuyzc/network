#include <stdio.h>
#define PI
#ifndef PI 

#ifdef SSH
#define SS_H
#endif

void test2()
{
    printf("aaa");
}
#else

void test2()
{
    printf("bbb");
}

#endif
int main(void)
{
    test2(); 
	return 0;
}

