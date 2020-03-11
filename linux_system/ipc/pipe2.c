#include "hyzc.h"

int main(int args, char *argv[])
{
    int fd[2],  pipen;
	pid_t pid;
    pipen = pipe(fd);
    if(pipen == -1){	
		sys_err("pipen error\n", 2);
	}	

	pid = fork();
	if(pid == -1){
		sys_err("fork error\n", 3);
	}

    if(pid > 0){
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", NULL);
		
	}

    if(pid == 0){
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", "-l", NULL);
	}


	return 0;
}

