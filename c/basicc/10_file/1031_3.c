#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("1.out", "r"); 
	while(!feof(fp))
	{
		printf("%c", fgetc(fp));
	}
    return 0;
}

