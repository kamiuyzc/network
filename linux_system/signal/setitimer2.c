#include "hyzc.h"
#include <sys/time.h>

int main(int args, char *argv[])
{
	struct itimerval new_obj, old_obj;
	new_obj.it_interval.tv_sec = 10;
    new_obj.it_interval.tv_usec = 1000;
	new_obj.it_value.tv_sec = 5;
	new_obj.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &new_obj, &old_obj);  

	sleep(2);
	printf("%ld %ld %ld %ld\n", old_obj.it_interval.tv_sec, old_obj.it_interval.tv_usec, old_obj.it_value.tv_sec ,old_obj.it_value.tv_usec);
	new_obj.it_value.tv_sec = 4;
    setitimer(ITIMER_REAL, &new_obj, &old_obj);  
	printf("%ld %ld %ld %ld\n", old_obj.it_interval.tv_sec, old_obj.it_interval.tv_usec, old_obj.it_value.tv_sec ,old_obj.it_value.tv_usec);
	return 0;
}

