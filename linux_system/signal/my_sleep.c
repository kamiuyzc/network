#include "hyzc.h"
#include <signal.h>

void fun(int signum)
{
	;
}

void mysleep(int count)
{
    struct sigaction newact;
	newact.sa_handler = fun;
    sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;

    sigaction(SIGALRM, &newact, NULL);


	sigset_t set, old_set;
	sigemptyset(&set);
	sigaddset(&set, SIGALRM);
	sigprocmask(SIG_BLOCK, &set, NULL);

	alarm(count);

	old_set = set;
	sigdelset(&old_set, SIGALRM);
    sigsuspend(&old_set);
	alarm(0);
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	//pause();
}

int main(int args, char *argv[])
{
	mysleep(1);
	printf("sleep over");
	return 0;
}

