#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
    
	printf("start fork\n");
	int n = fork();
	if(n < 0){
        perror("fork error \n");
	}
	else if(n == 0){
		printf("child process %d %d %d\n", n, getpid(), getppid());
	}
	else{ 
		printf("parent process %d %d %d\n", n, getpid(), getppid());
	}
	printf("end fork\n");
	return 0;
}

