#include "hyzc.h"
#include <string.h>
#include <pthread.h>

int g = 30;
void *tfn(void * args)
{
    int *p = (int *)args;
	g = 40;
	printf("child thread %d %lu \n", *p, pthread_self());
	return NULL;	
}

int main(int args, char *argv[])
{
    pthread_t tid;
	int res;
	int i = 10;
	int *p = &i;
	res = pthread_create(&tid, NULL, tfn, (void *)p);
	if(res != 0){
		fprintf(stderr, "pthread create %s error \n", strerror(res));
	}
	sleep(1);
	printf("main thread %d %lu %lu \n", g, pthread_self(), tid);

	return 0;
}

