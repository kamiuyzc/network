#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int args, char *argv[])
{
	int i, status; 
	pid_t pid, wpid;
	for(i = 0;i < 5;i++){
		pid = fork();
		if(pid == 0){
			break;
		}
		if(i == 2){
			wpid = pid;
			printf("child's 2 pid %d\n", wpid );
		}

	}

	if(i == 5){
		printf("parent process %d\n", getpid());
		while(1)
		{
			wpid = waitpid(wpid, &status, 0);
			if(wpid > 0){
				printf("wait child %d and return %d\n", wpid, WIFEXITED(status));
			}
			else if(wpid == 0){
				printf("waiting child over\n");
			}
			else{
				printf("wati no child to wait\n");
				break;
			}
		    sleep(1);
		}

	}
	else{
		sleep(5);
		printf("child process %d\n", getpid());
	}
	return 0;
}

