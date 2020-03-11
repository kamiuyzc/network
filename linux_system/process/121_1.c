#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	pid_t pt;
    pt = fork();
	if(pt < 0){
		perror("fork error");
	}
	else if(pt == 0){
		printf("child process\n");
        execlp("sleep", "sleep", "100", NULL);

		perror("execp error\n");
	}
	else{
		printf("parent process\n");
	}
	printf("all end\n");
	return 0;
}

