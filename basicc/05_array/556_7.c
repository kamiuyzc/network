#include <stdio.h>

int main(void)
{
	int i, j;
	char str1[] = "10 + 20 = ";
	sscanf(str1, "%d + %d = ", &i, &j); 
	printf("result is :%d\n", i + j);

	char str2[100];
	sprintf(str2, "%d + %d = %d", i, j, i+j);
	printf("the result is %s", str2);


	return 0;
}

