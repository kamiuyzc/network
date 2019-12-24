#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *str = "123abcd456abcd888888abcdlalabcdaaa"; 
	char *p = str;
	int n = 0;
	while(1)
	{
	    p = strstr(p, "abcd");	
		if (p == NULL)
		{
			break;
		}
		else
		{
            n++;
			p = p + sizeof("abcd") ;
		}
	}
	printf("result is %d\n", n);
    return 0;
}

