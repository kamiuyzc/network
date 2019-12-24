#include <stdio.h>
#include <stdlib.h>

int basicatoi(char *p);
int myatoi(char *p);


int basicatoi(char *p)
{
	int value = atoi(p);
	printf("basic atoi result is %d\n", value);
}

int myatoi(char *p)
{
	int result = 0;
	char op = 0;
	if (*p == '-' || *p == '+')
	{
		op = *p;
		p++;
	}
	while(*p != '\0')    
	{
        result = result * 10 + *p - '0';
		p++;
	}
    if (op == '-')
	{
		result = 0 - result;
	}
	printf("myatoi result is %d\n", result);
}

int main(int argc, char *argv[]) {
	char a[] = "+123";
	char b[] = "-123";
	char c[] = "123";
	basicatoi(a);
	basicatoi(b);
	basicatoi(c);
	myatoi(a);
	myatoi(b);
	myatoi(c);
	return 0;
}

