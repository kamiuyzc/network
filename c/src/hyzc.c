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
	if(rvalue == -1){
		perror(str);
		exit(status);
	}
}
