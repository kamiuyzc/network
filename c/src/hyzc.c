#include "hyzc.h"

void get_radom_array(int *array, int n)
{
	int i;
	unsigned int tm = (unsigned int)time(NULL);
	srand(tm);
	for(i = 0;i < n;i++)
	{
		array[i] = rand() % 100;
	}
}

void sys_err(int rvalue, const char *str, int status)
{
	char buf[1024] = {0};
	if(rvalue == -1){
		sprintf(buf, "%s error happen\n", str);
		perror(str);
		exit(status);
	}
}

void pthread_err(int rvalue, const char *str, int status)
{
	char buf[1024] = {0};
	if(rvalue != 0){
		fprintf(stderr, "pthread %s error: %s\n",str, strerror(rvalue));
		exit(status);
	}
}
