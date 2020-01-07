#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("aa\n"); 
	//fclose(stdout);
    printf("bb\n"); 
	perror("close stdout error");
	fclose(stderr);
	perror("close stdout error");
	int a;
	//fclose(stdin);
	scanf("%d", &a);
    printf("int %d",a);
    return 0;

}

