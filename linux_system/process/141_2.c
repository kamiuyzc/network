#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int args, char *argv[])
{
	pid_t pid, pid_w = 0; 
	int status;
	pid = fork();
	if(pid == 0){
		while(1)
		{
			break;
			printf("child process %d\n", getpid());
		}
		printf("child process %d\n", getpid());
		sleep(3);
		exit(2);
	}
	else if(pid > 0){
		printf("father process %d\n", getpid());
		printf("return wait %d\n", pid_w);
		while(1){
			pid_w = waitpid(-1, &status, WNOHANG);
			pid_w = waitpid(-1, &status, 0);
			printf("wait return is %d\n", pid_w);
			if(pid_w > 0)
			{
				if(WIFEXITED(status)){
					printf("wait child %d nomal exit return value %d\n", pid_w, WEXITSTATUS(status));
				}
				if(WIFSIGNALED(status)){
					printf("wait child %d return signal value %d\n", pid_w, WTERMSIG(status));
				}
			}
			if(pid_w == 0){
				printf("wait child do not over\n");
			}
			else{
				perror("wait11 error\n");
				printf("over");
				break;
			}
			sleep(1);

		}
	}
	else{
		perror("fork error\n");
	}
	return 0;
}

