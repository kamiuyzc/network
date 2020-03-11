#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int a = 100;
int main(int args, char *argv[])
{
	pid_t pn = fork();
	if(pn < 0){
		perror("fork error:");
	}
	else if (pn == 0){
		a = 300;
		printf("child %d\n", a);
	}
	else{
		a = 200;
		printf("father %d\n", a);
	}

	return 0;
}

