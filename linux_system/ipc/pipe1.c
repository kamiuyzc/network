#include "hyzc.h"

int main(int args, char *argv[])
{
	int fd[2], n, read_n, write_n;
	pid_t pid;
    n = pipe(fd);
	if(n < 0){
		sys_err("pipe error", 4);
	}

	char str[] = "hello yzc\n";
	char buf[1024] = {0};

    pid = fork();
    if(pid < 0){
		sys_err("fork error\n", 2);
	}

	else if(pid == 0){
        close(fd[1]);
        close(fd[0]);
		printf("child process before read\n");
		read_n = read(fd[0], buf, strlen(str));
		printf("child process after read %d\n", read_n);
		printf("%s\n", buf);
	}
	
	else{
        close(fd[0]);
		printf("parent process before write\n");
		sleep(1);
		write_n = write(fd[1], str, strlen(str));
		printf("parent process after write %d\n", write_n);
        close(fd[1]);
	}
	return 0;
}

