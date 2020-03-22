#include "hyzc.h"
#include <pthread.h>

void *tfn(void *args){
	long int *i;
	i = (long int *)args;
	printf("thread %ld %lu\n", *i, pthread_self());
    return NULL;
}

int main(int args, char *argv[])
{
	pthread_t tid; 
	long int i;
	int res;
	for(i = 0;i < 5;i++){
		res = pthread_create(&tid, NULL, tfn, (void *)(&i));
		if(res != 0){
			fprintf(stderr, "pthread create error:%s\n", strerror(res));
		}
	}
	sleep(1);
	printf("main thread %lu\n", pthread_self());
	return 0;
}

