#include "hyzc.h"
#include <signal.h>

void fun(int signo)
{
	printf("signal happen %d", signo);
	return ;
}

int main(int args, char *argv[])
{
    signal(SIGHUP, fun); 

	pause();

	return 0;
}

