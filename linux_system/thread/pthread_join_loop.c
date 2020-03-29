#include "hyzc.h"
#include <pthread.h>

void *tfn(void *args)
{
	long int * i = (long int *)malloc(sizeof(long int));
    	
	*i = (long int)args * 10;
    printf("pthread %ld %lu\n", *i, pthread_self());
	pthread_exit((void *)i);
}

int main(int args, char *argv[])
{
    int res;
	long int i;
	pthread_t tids[5];
	long int *n[5];

	for(i = 0;i < 5;i++){
		res = pthread_create(&tids[i], NULL, tfn, (void *)i);
		pthread_err(res, "pthread create", 1);
	}

	for(i = 0;i < 5;i++){
		pthread_join(tids[i], (void **)&n[i]);
		printf("%d %ld\n", i, *n[i]);

	}
	sleep(2);

	return 0;
}

