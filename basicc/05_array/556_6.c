#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "abcdef";
	char str2[] = {'a', 'b', 'c', '\0'}; 
	char str3[] = {'\0', 'b', 'c', '\0'};
	printf("str1 sizeof is %ld strlen is %ld\n", sizeof(str1),strlen(str1));
	printf("str2 sizeof is %ld strlen is %ld\n", sizeof(str2),strlen(str2));
	printf("str3 sizeof is %ld strlen is %ld\n", sizeof(str3),strlen(str3));
	return 0;
}

