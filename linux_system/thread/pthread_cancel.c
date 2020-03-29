#include "hyzc.h"
#include <pthread.h>

struct student
{
	int id;
	char name[50];
};

void *tfn(void *args)
{
	struct student *tmp = (struct student *)args;
	while(1)
	{
	    sleep(1);
	    printf("thread 1 %d %s\n", tmp -> id, tmp -> name);
	}
	pthread_exit((void *)tmp);
}

int main(int args, char *argv[])
{
    pthread_t tid;  
	int res;
    struct student * s1 = (struct student *)malloc(sizeof (struct student));
	s1 -> id = 10;
	strcpy(s1 -> name, "abc");
	
	res = pthread_create(&tid, NULL, tfn, (void *)s1);
	sleep(5);
	//pthread_detach(tid);
	pthread_err(res, "pthread create", 1);

	printf("main done %lu \n", tid);

	pthread_cancel(tid);
	void *p;
	res = pthread_join(tid, (void **)&p);
	if(p == PTHREAD_CANCELED){
		printf("ok\n");
	}
	//printf("thread 1 return %d %s\n", p -> id, p -> name);

	


	return 0;
}

