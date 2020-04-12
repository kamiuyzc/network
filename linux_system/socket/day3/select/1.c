#include "hyzc.h"

int main(int args, char *argv[])
{
    pid_t pid;
	int i;

	for(i = 0;i < 1024;i++){
		pid = fork();
		y_sys_err(pid, "fork", 1);
		if(pid == 0){
	        execl("./client.c.out", "client.c.out", NULL);	
		}
	}
	return 0;
}

