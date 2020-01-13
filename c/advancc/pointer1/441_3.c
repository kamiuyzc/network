#include <stdio.h>
void mycopy1(char *dst, char *src)
{
	for(;*src!= '\0';dst++, src++)
	{
        *dst = *src;
	}
	dst = '\0';


}

void mycopy2(char *dst, char *src)
{
    while(*src != '\0')
	{
        *dst++ = *src++;
	}
}

int mycopy3(char *dst, char *src)
{
	if(dst == NULL || src == NULL)
	{
		printf("Null point");
		return -1;
	}
    while(*dst++ = *src++){}
	return 0;
}

int main(int argc, char *argv[])
{
	char *str1 = "abcde";

    char a1[100]  = {0};
    mycopy1(a1, str1);
	printf("a1 %s\n", a1);

    char a2[100]  = {0};
    mycopy2(a2, str1);
	printf("a2 %s\n", a2);

    char a3[100]  = {0};
    mycopy3(a3, str1);
	printf("a3 %s\n", a3);
    return 0;
}

