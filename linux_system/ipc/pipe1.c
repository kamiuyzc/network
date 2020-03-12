#include "hyzc.h"

int main(int args, char *argv[])
{
	int fd[2], n, read_n, write_n;
	pid_t pid;
    n = pipe(fd);
	sys_err(n, "pipe error", 4);


	char str[] = "hello yzc\n";
	char buf[1024] = {0};

    pid = fork();
	sys_err(pid, "fork error\n", 2);

	if(pid == 0){
        close(fd[1]);
		printf("child process before read\n");
		read_n = read(fd[0], buf, strlen(str));
		printf("child process after read %d\n", read_n);
		printf("%s\n", buf);
        close(fd[0]);
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

