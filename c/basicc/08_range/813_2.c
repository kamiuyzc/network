#include <stdio.h>
extern int s;
static int sv = 20;

static void fun3(void)
{
    printf("file 2 fun3 global s is %d\n", ++s);    
    printf("file 2 fun3 static sv  is %d\n", ++sv);    
}

void fun2(void)
{
    printf("fun2 global s is %d\n", ++s);    
    printf("fun2 static sv  is %d\n", ++sv);    
	fun3();
}

