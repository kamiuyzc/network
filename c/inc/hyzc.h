#ifndef _HYZC_H_

#define _HYZC_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

void get_radom_array(int *array, int n);
void sys_err(const char *str, int status);

#endif
