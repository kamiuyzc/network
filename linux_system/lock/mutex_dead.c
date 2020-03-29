#include "hyzc.h"
#include <pthread.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void * lock1(void *argv){
	int res1;
	printf("lock1 start\n");
	res1 = pthread_mutex_lock(&mutex1);
	pthread_err(res1, "pthread1 lock1 error", 1);
	sleep(2);
	printf("sleep 1 end\n");
	res1 = pthread_mutex_lock(&mutex2);
	pthread_err(res1, "pthread1 lock2 error", 1);

	res1 = pthread_mutex_unlock(&mutex1);
	res1 = pthread_mutex_unlock(&mutex2);
	printf("lock 1 end\n");
	return NULL;
	
}

void * lock2(void *argv){
	int res2;
	printf("lock2 start\n");
	res2 = pthread_mutex_lock(&mutex2);
	pthread_err(res2, "pthread2 lock2 error", 1);
	sleep(2);
	printf("sleep 2 end\n");
	res2 = pthread_mutex_lock(&mutex1);
	pthread_err(res2, "pthread2 lock1 error", 1);

	res2 = pthread_mutex_unlock(&mutex1);
	res2 = pthread_mutex_unlock(&mutex2);
	printf("lock 2 end\n");
	return NULL;
}

int main(int args, char *argv[])
{
	int res;
    pthread_mutex_init(&mutex1, NULL); 
    pthread_mutex_init(&mutex2, NULL); 

	pthread_t tid1, tid2;
	res = pthread_create(&tid1, NULL, lock1, NULL);
	pthread_err(res, "pthread create 1 error", 1);

	res = pthread_create(&tid2, NULL, lock2, NULL);
	pthread_err(res, "pthread create 2 error", 2);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}

