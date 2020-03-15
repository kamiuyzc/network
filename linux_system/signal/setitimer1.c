#include "hyzc.h"
#include <sys/time.h>
#include <signal.h>

void fun()
{
	printf("alarm happen\n");
	system("date +%T.%N");
}

int main(int args, char *argv[])
{
	signal(SIGALRM, fun);
	struct itimerval new, old;
	new.it_interval.tv_sec = 5;
	new.it_interval.tv_usec = 0;
	new.it_value.tv_sec = 3;
	new.it_value.tv_usec = 100000;
	printf("before set time:\n");

	system("date +%T.%N");

	setitimer(ITIMER_REAL, &new, &old); 

	printf("after set time :\n");
	system("date +%T.%N");
	while(1);
	return 0;
}

