#include "hyzc.h"
#include <pthread.h>

pthread_mutex_t mutid;


void *tfn(void *argv)
{
	int res_s;
    while(1){
		res_s = pthread_mutex_lock(&mutid);
		pthread_err(res_s, "lock error", 2);
		printf("1 hello ");
		sleep(rand() % 3);
		printf("world\n");
		res_s = pthread_mutex_lock(&mutid);
		pthread_err(res_s, "unlock error", 2);
		sleep(rand() % 3);
	}
    return NULL;
}

int main(int args, char *argv[])
{
	srand(time(NULL));
	int res_m;
	pthread_t tid;
    res_m = pthread_mutex_init(&mutid, NULL);
    pthread_err(res_m, "init mutex error", 1);

	pthread_create(&tid, NULL, tfn, NULL);

	int n = 5;
    while(n--){
		res_m = pthread_mutex_lock(&mutid);
		pthread_err(res_m, "lock error", 3);
		printf("2 HELLO ");
		sleep(rand() % 2);
		printf("WORLD\n");
		res_m = pthread_mutex_unlock(&mutid);
		pthread_err(res_m, "unlock error", 2);
		sleep(rand() % 3);
	}
	pthread_cancel(tid);
	pthread_join(tid, NULL);
    res_m = pthread_mutex_destroy(&mutid);
    pthread_err(res_m, "destroy mutex error", 1);

	return 0;
}

