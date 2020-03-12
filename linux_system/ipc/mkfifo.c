#include "hyzc.h"
#include <sys/stat.h>

int main(int args, char *argv[])
{
	int n;
    n = mkfifo("mymkfifo", 0755);
	sys_err(n, "mkfifo error \n", 1);
	return 0;
}

