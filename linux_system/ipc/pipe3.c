#include "hyzc.h"
#include <sys/wait.h>

int main(int args, char *argv[])
{
	int fd[2], n, read_n, write_n, i;
	pid_t pid;
    n = pipe(fd);
	sys_err(n, "pipe error", 1);

	for(i = 0;i < 2;i++){
		pid = fork();
		sys_err(pid, "fork error", 2);
		if(pid == 0){
			break;
		}
	}

	if(i == 2){
		//close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}

	if(i == 0){
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execlp("ls", "ls", NULL);
	}


	if(i == 1){
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execlp("wc", "wc", "-l", NULL);
	}

	return 0;
}

