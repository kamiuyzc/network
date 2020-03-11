#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("child process %d\n", getpid()); 
		sleep(10);
	}
	else if(pid > 0){
		printf("father process %d\n", getpid()); 
		while(1){
			printf("father process %d\n", getpid()); 
			sleep(1);
		}
	}
	else{
		perror("fork error\n");
	}
	return 0;
}

