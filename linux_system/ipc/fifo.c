#include "hyzc.h"

int main(int args, char *argv[])
{
    int fd, pipd, pid; 
	char buf[1024];

	fd = open("mymkfifo", O_RDWR, 0755);
	sys_err(fd, "open error\n", 1);
    
	pid = fork();
	
	sys_err(pid, "fork error\n", 2);
	if(pid == 0){
		char *s = "read info test\n";
		write(fd, s, strlen(s));
	}

	if(pid > 0){
		sleep(1);
		read(fd, buf, 1024);
		printf("%s\n", buf);
	}

	close(fd);

	return 0;
}

