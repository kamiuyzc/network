#include "hyzc.h"
#include <sys/stat.h>

int main(int args, char *argv[])
{
    pid_t pid;
	int res, fd;

	pid = fork();
	sys_err(pid, "fork", 1);
	if(pid > 0){
		exit(0);
	}
    pid = setsid();
	sys_err(pid, "sid", 2);
	res = chdir("/home/yangzhengchu/");
	sys_err(res, "chdir", 3);

	umask(0022);

	close(STDIN_FILENO);
	fd = open("/dev/null", O_RDWR);
	sys_err(fd, "open", 4);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);
	while(1){
        
	}

	return 0;
}

