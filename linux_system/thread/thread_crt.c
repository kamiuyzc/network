#include "hyzc.h"
#include <pthread.h>

void *fun(void *args)
{
	printf("thread is %ld\n", pthread_self());
	int *i;
	i = (int *)args;
	int *p;
	p = (int *)malloc(sizeof(int));
	printf("fun lala %d\n", *i);

	return (void *)p;
}

int main(int args, char *argv[])
{

	pthread_t t;
	int a = 20;
	pthread_create(&t, NULL, fun, (void *)&a);
	printf("main thread %ld\n", t);
	while(1);
	return 0;
}

