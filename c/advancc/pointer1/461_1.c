#include <stdio.h>

void getStr1Str2(char *source, char *buf1, char *buf2)
{
	char *tmp;
	tmp = source;
	int i = 0; 
	while(*tmp != '\0')
	{
		if(i % 2 == 0)
		{
            *buf1++ = *tmp++;
		}
		else
		{
            *buf2++ = *tmp++;
		}
		i++;
	}
	*buf1 = '\0';
	*buf2 = '\0';
}

int main(int argc, char *argv[])
{
	char a[] = "1a2b3d4z";
	char b[10];
	char c[10];
	getStr1Str2(a, b, c);
	printf("%s\n", b);
	printf("%s\n", c);
	return 0;
}

