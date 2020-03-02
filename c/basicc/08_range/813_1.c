#include <stdio.h>
extern int s;
static int sv = 10;

static void fun3(void)
{
    printf("file1 static fun3 global s is %d\n", ++s);    
    printf("file1 static fun3 static sv  is %d\n", ++sv);    
}

void fun1(void)
{
    printf("fun1 global s is %d\n", ++s);    
    printf("fun1 static sv  is %d\n", ++sv);    
	fun3();
}

