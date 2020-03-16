#include "hyzc.h"
#include <signal.h>
#include <sys/wait.h>

void catch_childs(int signo)
{

	int status;
	pid_t pid;
	while((pid = waitpid(-1, &status, 0)) != -1)
	{
		
		if(WIFEXITED(status)){
			printf("catch child %d %d\n", pid, WEXITSTATUS(status));
		}
	}
	return ;
}
int main(int args, char *argv[])
{
	sigset_t aset;
	sigemptyset(&aset);
	sigaddset(&aset, SIGCHLD);
    sigprocmask(SIG_BLOCK, &aset, NULL);

	int i;
	pid_t pid;
	for(i = 0;i < 15;i++){
		pid = fork();	
		sys_err(pid, "fork", 1);
		if(pid == 0){
			break;
		}
	}

	if(i == 15){
		struct sigaction new, old;
		new.sa_handler = catch_childs;
		sigemptyset(&new.sa_mask);
		new.sa_flags = 0;
		sleep(1);
		sigaction(SIGCHLD, &new, &old);

		sigprocmask(SIG_UNBLOCK, &aset, NULL);

		printf("I am a father %d\n", getpid());
		while(1);
	}
	else{
		printf("I am a child %d\n", getpid());
		exit(i);
	}

	return 0;
}

