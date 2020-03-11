#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int args, char *argv[])
{
    pid_t pid, pid_w; 
	int status;
	pid = fork();
	if(pid == 0){
		while(1)
		{
			sleep(1);
			printf("child process %d\n", getpid());
		}
		printf("child process %d\n", getpid());
		exit(1);
	}
	else if(pid > 0){
		printf("father process %d\n", getpid());
		//pid_w = wait(NULL);
		pid_w = wait(&status);
		if(WIFEXITED(status)){
			printf("child %d nomal exit return value %d\n", pid_w, WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("child %d return signal value %d\n", pid_w, WTERMSIG(status));
		}
	}
	else{
		perror("fork error\n");
	}
	return 0;
}

