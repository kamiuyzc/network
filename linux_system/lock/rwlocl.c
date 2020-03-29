#include "hyzc.h"
#include <pthread.h>
int counter = 0;
pthread_rwlock_t rwlock;

void * readlock(void * argv)
{
	long int i = (long int)argv;
	//printf("read start %ld\n", i);
	while(1){
		pthread_rwlock_rdlock(&rwlock);
		printf("read thread id = %ld counter = %d\n", i, counter);	
		pthread_rwlock_unlock(&rwlock);
		usleep(1000000);
	}

	return NULL;
}

void * writelock(void * argv)
{
	while(1){
		long int i = (long int)argv;
		pthread_rwlock_wrlock(&rwlock);
		printf("write thread id = %ld counter = %d\n", i, ++counter);	
		pthread_rwlock_unlock(&rwlock);
		usleep(1000000);
	}
	return NULL;
}

int main(int args, char *argv[])
{
	int res;
	long int i;
	pthread_t tid[8];
	res = pthread_rwlock_init(&rwlock, NULL);	
	pthread_err(res, "rwlock init", 1);

	for(i = 0;i < 3;i++){
		res = pthread_create(&tid[i], NULL, writelock, (void *)i);
		pthread_err(res, "pthread write", 1);
	}

	for(i = 0;i < 5;i++){
		res = pthread_create(&tid[i + 3], NULL, readlock, (void *)i);
		pthread_err(res, "pthread read", 1);
	}

	for(i = 0;i < 8;i++){
		res = pthread_join(tid[i], NULL);
		pthread_err(res, "pthread join", 1);
	}

	res = pthread_rwlock_destroy(&rwlock);	
	pthread_err(res, "rwlock destroy", 1);
	return 0;
}

