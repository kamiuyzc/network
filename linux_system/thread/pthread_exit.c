#include "hyzc.h"
#include <pthread.h> 
#include <string.h>

int fun()
{
    //return 110;	
	pthread_exit(NULL);
}
void *tfn(void *args)
{
	int j = 3;
	long int i = (long int)args;
	int k;
	sleep(i);
	if(i == 2){
		//pthread_exit(NULL);
		//return 0;
		//exit(0);
		j = fun();
	}
	printf("ok %ld %d\n",i,  j);
	return NULL;
}

int main(int args, char *argv[])
{
	int ret;
	long int i;
	pthread_t tid;
	for(i = 0;i < 5;i++){
		ret = pthread_create(&tid, NULL, tfn, (void *)i);
		if(ret != 0){
			fprintf(stderr, "pthread create error %s\n", strerror(ret));
		}
	}
	pthread_exit(NULL);
	return 0;
}

