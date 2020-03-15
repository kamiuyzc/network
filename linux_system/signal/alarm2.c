#include "hyzc.h"
#include <signal.h>

void fun(){
	printf("signal happen\n");
}

int main(int args, char *argv[])
{
	signal(SIGALRM, fun);
    int res;
	res = alarm(5);
	printf("%d\n", res);
	sleep(3);
	res = alarm(4);
	printf("%d\n", res);
	sleep(5);
	res = alarm(5);
	printf("%d\n", res);
	res = alarm(0);
	printf("%d\n", res);
	return 0;
}

