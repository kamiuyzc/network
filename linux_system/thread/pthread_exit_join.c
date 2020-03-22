#include "hyzc.h"
#include <pthread.h>
#include <string.h>

struct student
{
	int id;
	char a[10];
};

void * tfn(){

	struct student *p = (struct student *)malloc(sizeof(struct student));
	p -> id = 100;
	strcpy(p -> a , "yzc");
	//pthread_exit((void *)p);
	return (void *)p;
}
int main(int args, char *argv[])
{

	pthread_t tid;
	int res;
	res = pthread_create(&tid, NULL, tfn, NULL);
	if(res != 0){
		fprintf(stderr, "pthread create error %s\n", strerror(res));
	}
	struct student *q; 
    pthread_join(tid, (void **)&q);
	//printf("lalalal %d %s\n", q-> id, q -> a);
	printf("lalalal %d %s\n", q-> id, q -> a);

	pthread_exit(NULL);
	return 0;
}

