#include "hyzc.h"
#include <signal.h>

int nc = 0;
int flag = 0;

void do_child_fun(int signal){
	printf("sig call child %d \n", nc);
	nc += 2;
	flag = 1;
	sleep(1);
}

void do_parent_fun(int signal){
	printf("sig call parent %d \n", nc);
	nc += 2;
	flag = 1;
	sleep(1);
}

int main(int args, char *argv[])
{
	pid_t pid;
	struct sigaction act;
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR2);
	sigaddset(&set, SIGUSR1);
	sigprocmask(SIG_BLOCK, &set, NULL);

	pid = fork();
	sys_err(pid, "fork", 1);

	if(pid > 0){
		act.sa_handler = do_parent_fun;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1, &act, NULL);

		sigprocmask(SIG_UNBLOCK, &set, NULL);
		nc = 1;
		do_parent_fun(0);

		while(1){
			if(flag == 1){
				kill(pid, SIGUSR2);
				flag = 0;
			}
		}
	}
	else{
		act.sa_handler = do_child_fun;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR2, &act, NULL);

		sigprocmask(SIG_UNBLOCK, &set, NULL);
		nc = 2;

		while(1){
			if(flag == 1){
				kill(getppid(), SIGUSR1);
				sleep(1);
				flag = 0;
			}
		}

	}

	return 0;
}

