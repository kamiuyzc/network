#include "hyzc.h"
#include <pthread.h>
#define SIZE 0x10000
void *tfn(void * argv)
{
	while(1){
		sleep(1);
	}

}

int main(int args, char *argv[])
{
	int res, i = 0, detachstate;
    pthread_t tid;	
	pthread_attr_t attr;
	size_t stacksize;
	void *stackaddr;

    pthread_attr_init(&attr);
    pthread_attr_getstack(&attr, &stackaddr, &stacksize);
    pthread_attr_getdetachstate(&attr, &detachstate);

	if (detachstate == PTHREAD_CREATE_DETACHED)   //默认是分离态
		printf("thread detached\n");
	else if (detachstate == PTHREAD_CREATE_JOINABLE) //默认时非分离
		printf("thread join\n");
	else
		printf("thread un known\n");

	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	printf("lalalalalalalalallaal\n");

    while(1){
		stackaddr = malloc(SIZE);
		///*
		if(stackaddr == NULL)
		{
			printf("malloc lala %d\n", i);
			perror("malloc");
			exit(1);
		}
		stacksize = SIZE;
		res = pthread_attr_setstack(&attr, stackaddr, stacksize);
		if (res != 0){
			printf("set stack attr %s id: %d\n", strerror(res), i);
			exit(1);
		}
		//*/

		//printf("%ld %p\n", stacksize, stackaddr);

	    res = pthread_create(&tid, &attr, tfn, NULL);	
		if (res != 0){
			printf("%p %ld\n", stackaddr, stacksize);
			printf("set create %s %d\n", strerror(res), i++);
			exit(2);
		}
		i++;

		//printf("%s %d\n", strerror(res), i++);
		//printf("%d\n", i++);
	}
	return 0;
}

