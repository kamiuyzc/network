#include "hyzc.h"
#include <semaphore.h>
#include <pthread.h>

#define NUM 5
int quene[5] = {0};

sem_t blank_number, product_number;

void * consumer(void * argv)
{
	int i = 0;
	while(1){
		sem_wait(&product_number);
		printf("consumer %d\n", quene[i]);
		quene[i] = 0;
		sem_post(&blank_number);
		i = (i + 1) % 5;
		usleep(rand() % 100);
	}
    return NULL;
}

void * producter(void * argv)
{
	int i = 0, value;
	while(1){
		value = rand() % 100;
        sem_wait(&blank_number);
		quene[i] = value;
		printf("producter %d \n", quene[i]);
		sem_post(&product_number);
		i = (i + 1) % 5;
		usleep(rand() % 100);
		
	}
    return NULL;
}

int main(int args, char *argv[])
{
	srand(time(NULL));
	int res;
    pthread_t pid, cid;

    res = sem_init(&blank_number, 0, 5);
	sys_err(res, "sem init blank", 1);
	sem_init(&product_number, 0, 0);
	sys_err(res, "sem init product", 1);


	res = pthread_create(&cid, NULL, consumer, NULL);
	pthread_err(res, "pthread create cousmer errror", 1);
	res = pthread_create(&pid, NULL, producter, NULL);
	pthread_err(res, "pthread create producter errror", 1);

	res = pthread_join(cid, NULL);
	pthread_err(res, "pthread join consumer errror", 1);
	res = pthread_join(pid, NULL);
	pthread_err(res, "pthread join producter errror", 1);

	res = sem_destroy(&blank_number);
	sys_err(res, "sem destroy blank", 1);
	res = sem_destroy(&product_number);
	sys_err(res, "sem destroy product", 1);

	return 0;
}

