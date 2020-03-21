#include "hyzc.h"

int main(int args, char *argv[])
{
    pid_t pid, npid;
	pid = fork();
	sys_err(pid, "fork", 1);
	if(pid > 0){
		sleep(5);
		printf("parent pid %d ppid %d pgid %d sid %d\n",getpid(), getppid(), getpgid(getpid()), getsid(getpid()));
		printf("father done\n");
	}
	else{
		printf("chid pid %d ppid %d pgid %d sid %d\n",getpid(), getppid(), getpgid(getpid()), getsid(getpid()));
		sleep(10);
        npid = setsid();
		printf("child pid %d ppid %d pgid %d sid %d\n",getpid(), getppid(), getpgid(getpid()), getsid(getpid()));
	    sys_err(npid, "fork", 1);
		while(1);
	}
	return 0;
}

