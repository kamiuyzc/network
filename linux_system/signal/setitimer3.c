#include "hyzc.h"
#include <sys/time.h>

int main(int args, char *argv[])
{
    struct itimerval new, old;
	int res;
	new.it_interval.tv_sec = 0;
	new.it_interval.tv_usec = 0;
	new.it_value.tv_sec = 1;
	new.it_value.tv_usec = 0;
	res = setitimer(ITIMER_REAL, &new, &old);
	int i = 0;
	while(1)
	{
		printf("%d\n", i++);
	}
	return 0;
}

