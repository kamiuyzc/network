#include "hyzc.h"
#include <pthread.h>

struct msg
{
	int id;
	struct msg *next; 
};

struct msg *head = NULL;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;

void * consumer(void * argv)
{
	struct msg *mp;
	while(1){
		printf("lala %ld before lock\n", pthread_self()%100);
		pthread_mutex_lock(&lock);
		printf("lala %ld get lock\n", pthread_self()%100);
		if (head == NULL){
			pthread_cond_wait(&has_product, &lock);
		    printf("lala %ld wait done\n", pthread_self()%100);
		}
		printf("lala %ld handle lock\n", pthread_self()%100);
		//printf("consumer 1 %ld %d\n", pthread_self());
		mp = head;
		head = head -> next;
		//printf("consumer %ld %d\n", pthread_self()%100, mp -> id);
		free(mp);
		printf("lala %ld release lock\n", pthread_self()%100);
		pthread_mutex_unlock(&lock);
		mp = NULL;
		sleep(rand() % 3);
	}
	return NULL;
}

void * producter(void * argv)
{
	int res;
	struct msg *mp;
	while(1){
		mp = (struct msg *)malloc(sizeof(struct msg));
		mp -> id =  rand() % 100;
		printf("product wait lock\n");
		res = pthread_mutex_lock(&lock);
		printf("product get lock\n");
		pthread_err(res, "lock in producter", 1);
		mp -> next = head;
		head = mp;
		//printf("product done %d\n", mp -> id);
		printf("product relases lock\n");
		res = pthread_mutex_unlock(&lock);
		pthread_err(res, "unlock in producter", 1);
		res = pthread_cond_signal(&has_product);
		pthread_err(res, "cond signal in producter", 1);
		sleep(rand() % 3);
	}
	return NULL;
}

int main(int args, char *argv[])
{
	int res;
	pthread_t cid, pid, cid2;
	srand(time(NULL));

	res = pthread_create(&cid, NULL, consumer, NULL);
	pthread_err(res, "create cousumer error", 1);
	res = pthread_create(&cid2, NULL, consumer, NULL);
	pthread_err(res, "create cousumer error", 1);
	res = pthread_create(&pid, NULL, producter, NULL);
	pthread_err(res, "create developer error", 2);

	res = pthread_join(cid, NULL);
	pthread_err(res, "join consumer error", 2);
	res = pthread_join(pid, NULL);
	pthread_err(res, "join developer error", 2);
	res = pthread_join(cid2, NULL);
	pthread_err(res, "join consumer2 error", 2);

	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&has_product);

	return 0;
}

