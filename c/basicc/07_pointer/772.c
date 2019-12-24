#include <stdio.h>

void mystrcat(char *dst, char *src);

void mystrcat(char *dst, char *src)
{
    char *p = dst;
    while(*p != '\0') 
	{
        p++;
	}

	while(*src != '\0')
	{
		*(p++) = *(src++);
	}
	*p = '\0';

}

int main(int argc, char *argv[])
{
    char src[] = "hello"; 
    char dst[100] = "1234"; 

	mystrcat(dst, src);
	printf("dst %s", dst);
    return 0;
}

