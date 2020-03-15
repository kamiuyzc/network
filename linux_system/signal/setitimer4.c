#include "hyzc.h"
#include <sys/time.h>
#include <signal.h>

void fun(){
	//system("hping3 -1 -c 10 --faster 127.0.0.2 -D");
	system("curl 127.0.0.3 &> /dev/null");
}
int main(int args, char *argv[])
{
    signal(SIGALRM, fun);

    struct itimerval new, old;
	new.it_interval.tv_sec = 0;
	new.it_interval.tv_usec = 100000;
	new.it_value.tv_sec = 1;
	new.it_value.tv_usec = 0;

	int res;
	res = setitimer(ITIMER_REAL, &new, &old);
	sys_err(res, "set timer fail\n", 1);
	while(1);
	return 0;
}

