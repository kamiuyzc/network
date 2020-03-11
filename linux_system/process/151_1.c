#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	int i, status;
	pid_t pid, wpid;
	for(i = 0;i < 3;i++){
		pid = fork();
		if(pid == -1){
			perror("fork child error\n");
		}
		if(pid == 0){
			if(i == 0){
				execlp("ps", "ps", NULL);
			}
			else if(i == 1){
				execl("./1.out", "1.out", NULL);
			}
			else{
				execl("./2.out", "2.out", NULL);
			}
			break;
		}
	}
	while(1){
		wpid = waitpid(-1, &status, WNOHANG);
		if(wpid == 0){
			printf("wait child processing\n");
		}
		else if(wpid < 0){
			perror("wait erro and end:\n");
			printf("wait end\n");
			break;
		}
		else{
			if(WIFEXITED(status)){
				printf("wait exit %d %d\n", wpid, WEXITSTATUS(status));	
			}
			if(WIFSIGNALED (status)){
				printf("wait signal %d %d\n", wpid, WTERMSIG(status));	
			}
		}
		sleep(1);
	}
	return 0;
}

