#include "hyzc.h"
#include <signal.h>

void fun(int signo)
{
	if(signo == SIGINT)
	{
		printf("before catch sig %d\n", signo);
		sleep(2);
		printf("after catch sig %d\n", signo);
	}
	else{

		printf("haha %d\n", signo);
		sleep(2);
		printf("after11  catch sig %d\n", signo);
	}
}

int main(int args, char *argv[])
{
	struct sigaction new, old;

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGQUIT);

	new.sa_handler = fun;
	new.sa_flags |= SA_RESTART;
	new.sa_mask = set;


	sigaction(SIGQUIT, &new, &old);
	char buf[1024] = {0};
	int res = read(0, buf, 100);
	sys_err(res, "error\n", 1);
	printf("result:%s", buf);
	return 0;
}

