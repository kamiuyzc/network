#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    int fd1, fd2; 
	fd1 = open("1.out", O_RDWR | O_CREAT | O_TRUNC, 0755);
	fd2 = open("2.out", O_RDWR | O_CREAT | O_TRUNC, 0755);
    printf("%d %d \n", fd1, fd2);	

	int n1 = dup2(fd1, fd2);
	if(n1 < 0){
		perror("dup2 1 error");
		exit(1);
	}


	write(fd2, "abc", 3);

	int n2 = dup2(fd2, STDOUT_FILENO);
	if(n2 < 0){
		perror("dup2 2 error");
		exit(1);
	}

	printf("ghi %d %d", n1, n2);
	return 0;
}

