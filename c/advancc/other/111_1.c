#include <stdio.h>
#include <stdio.h>
#include <string.h>

void fun(int n)
{
	if(n == 0)
	{
		printf("start\n"); 
	}
	else
	{
		fun(n - 1);
		printf("%d\n", n);
	}
}

int fun1(int n)
{
   if(n == 0) 
   {
	  return n; 
   }
   else
   {
      return n + fun1(n - 1);
   }
}

int fun2(int n)
{
	if(n == 0 || n == 1)
	{
		return n;
	}
	else
	{
        return fun2(n - 1) + fun2(n - 2);
	}
}

int main(void)
{
	fun(5); 
	return 0;
}


