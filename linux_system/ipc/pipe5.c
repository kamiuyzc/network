#include "hyzc.h"

int main(int args, char *argv[])
{
    int res, i, fd1[2], fd2[2];
	pid_t pid;

	res = pipe(fd1);
	sys_err(res, "pipe error\n", 1);
	res = pipe(fd2);
	sys_err(res, "pipe error\n", 1);
    
	for(i = 0;i < 2;i++){
		pid = fork();
	    sys_err(pid, "fork error\n", 2);
		if(pid == 0){
			break;
		};
	}

	if(i == 0){
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		dup2(fd1[1], STDOUT_FILENO);
		execlp("cat", "cat","/etc/passwd", NULL);
	}

    else if(i == 1){	
		close(fd1[1]);
		close(fd2[0]);
		res = dup2(fd1[0], STDIN_FILENO);
	    sys_err(res, "dup2 1 error\n", 2);

		res = dup2(fd2[1], STDOUT_FILENO);
	    sys_err(res, "dup2 2 error\n", 2);
		execlp("grep", "grep", "chu", NULL);
	}
	else{
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[1]);
		res = dup2(fd2[0], STDIN_FILENO);
	    sys_err(res, "dup3 3 error\n", 2);
		execlp("cut", "cut", "-d", ":", "-f", "7", NULL);
	}
	
	return 0;
}

