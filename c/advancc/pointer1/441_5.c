#include <stdio.h>
#include <string.h>
void reverse_string(char *p)
{
   int end = strlen(p) - 1;
   int start = 0;
   char tmp;
   while(start < end)
   {
	   tmp = p[start]; 
	   p[start] = p[end];
	   p[end] = tmp;
	   start++;
	   end--;
   }

}

int main(void)
{
	char a[] = "hello world!";
    reverse_string(a);
	printf("%s\n", a);
	return 0;
}

