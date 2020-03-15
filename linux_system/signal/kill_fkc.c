#include "hyzc.h"
#include <sys/signal.h>

int main(int args, char *argv[])
{
    pid_t pid, tmppid;
	int res, i;
	for(i = 0;i < 5;i++){
		pid = fork();
		sys_err(pid, "fork error\n", 1);
		if(pid == 0){
			break;
		}
		if(i == 3){
			tmppid = pid;
		}
	}

	if(i < 5){
		while(1){
			if(i == 3){
			    printf("child %d process %d\n", i, getpid());
			    sleep(3);
			}
		}
	}
	if(i == 5){
		//printf("sleep before father process need kill %d\n",tmppid);
		//sleep(5);
		//printf("sleep after father process need kill %d\n",tmppid);
		res = kill(tmppid, SIGKILL);
		sys_err(res, "kill error\n", 3);
	}
	return 0;

}

