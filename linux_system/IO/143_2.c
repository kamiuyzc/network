#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    int fp, n;

	fp = open("2.txt", O_CREAT | O_RDWR | O_TRUNC);
	if(fp == -1){
		perror("open error");
	}
	
	n = unlink("2.txt");
	if(n == -1){
		perror("unlink error");
	}

	char buf[] = "hello lala!";
	int len = strlen(buf);

    n = write(fp, buf, len);
	if(n == -1){
		perror("write error");
	}

	memset(buf, 0, len);
	lseek(fp, 0, SEEK_SET);

    n = read(fp, buf, len);
	if(n == -1){
		perror("write error");
	}
	printf("result is %s\n", buf);


	getchar();

	close(fp);

	return 0;
}

