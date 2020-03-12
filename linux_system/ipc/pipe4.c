#include "hyzc.h"
#include <sys/wait.h>


int main(int args, char *argv[])
{
    int fd[2], pid, pipd, i;
	char buf[1024] = {0};

	pipd = pipe(fd);
	sys_err(pipd, "pipe error\n", 2);

	for(i = 0;i < 2;i++){
		pid = fork();
		sys_err(pid, "fork error", 3);
		if(pid == 0){
			break;
		}
	}

    if(i == 0){
		char *s1 = "1.hello\n";
		close(fd[0]);
		write(fd[1], s1, strlen(s1));
		close(fd[1]);
	}
	else if(i == 1){
		char *s2 = "2.hello\n";
		close(fd[0]);
		write(fd[1], s2, strlen(s2));
		close(fd[1]);
	}
	else{
		close(fd[1]);
        sleep(1);
		read(fd[0], buf, 1024);
		printf("result:%s\n", buf);
		wait(NULL);
		wait(NULL);
	}
	return 0;
}

