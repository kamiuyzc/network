#include <stdio.h>

int main(void)
{
    fputc(65, stdout); 
	char ch;
	ch = fgetc(stdin);
	fprintf(stderr, "%c\n", ch);
	E
	return 0;
}

