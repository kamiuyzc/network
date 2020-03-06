#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
	int fd = open("1.out", O_RDWR | O_CREAT, 0755);
	if(fd < 0){
		perror("open error:");
		exit(1);
	}

	int newfd = dup(fd);
	if(newfd < 0){
		perror("open error:");
		exit(1);
	}
	
	write(newfd, "abcde", 5);
	printf("%d %d\n", fd, newfd);

	close(newfd);



	return 0;
}

