#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
    int n;
    char buf[1024];
	memset(buf, 0, 1024);
	n = read(STDIN_FILENO, buf, 1024);
	if(n == -1)
	{
		perror("read error");
	}
    printf("%s", buf);
	return 0;
}

