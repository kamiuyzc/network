#include "hyzc.h"
#include <pthread.h>

void * tfn(void * argv)
{
	sleep(1);
    printf("thread info\n");
	return NULL;
}
int main(int args, char *argv[])
{
    pthread_t tid;
	int res;
	pthread_attr_t attr_t;
	
	res = pthread_attr_init(&attr_t);
	pthread_err(res, "pthread init attr", 1);

	pthread_attr_setdetachstate(&attr_t, PTHREAD_CREATE_DETACHED);
	pthread_err(res, "pthread set detach attr", 1);



	res = pthread_create(&tid, &attr_t, tfn, NULL);
	pthread_err(res, "pthread create", 1);
	
	pthread_attr_destroy(&attr_t);
	pthread_err(res, "pthread destroy attr", 1);

	//pthread_detach(tid);
	//pthread_err(res, "pthread detach", 1);
	


    res = pthread_join(tid, NULL);
	pthread_err(res, "pthread join", 1);

	printf("main %d %ld\n", getpid(), pthread_self());

	pthread_exit((void *)0);

	return 0;
}

