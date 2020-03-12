#include "hyzc.h"

int main(int args, char *argv[])
{
    int fd1, fd2, len, n;
	pid_t pid;
	char *str1 = "---------test for shared fd in parent child process-----\n";
	char buf[1024] = {0};

	pid = fork();
	sys_err(pid, "fork error\n", 2);

	if(pid == 0){
        fd1 = open("1.out", O_WRONLY | O_CREAT | O_TRUNC);
	    sys_err(fd1, "child open error\n", 2);
        len = strlen(str1);
		n = write(fd1, str1, len);
	    sys_err(n, "write error\n", 3);	
		close(fd1);
	}
    else{	
        fd2 = open("1.out", O_RDONLY | O_CREAT | O_TRUNC);
		sleep(1);
	    sys_err(fd2, "father open error\n", 2);
		n = read(fd2, buf, 1024);
	    sys_err(n, "read error\n", 4);	
		write(STDOUT_FILENO, buf, strlen(buf));
		close(fd2);
	}

	return 0;
}

