#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int main(int args, char *argv[])
{
	char buf[] = "my name is key!";
	int fp, n;
	fp = open("1.out", O_RDWR| O_CREAT | O_TRUNC, 0777);

	if(fp == -1)
	{
		printf("%d %s\n", errno, strerror(errno));
		perror("open perror");
	}

	int len = strlen(buf);
	write(fp, buf, len);
	memset(buf, 0, len);
	lseek(fp, 0, SEEK_SET);
	read(fp, buf, len);

	printf("result:%s\n", buf);
	len = lseek(fp, 0, SEEK_END);
	printf("%d\n", len);

	n = lseek(fp, 19, SEEK_END);
	write(fp, "\0", 1);
	truncate("1.out", 50);
	printf("%d\n", n);
	close(fp);
	return 0;
}




