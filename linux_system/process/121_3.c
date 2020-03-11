#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int args, char *argv[])
{
    pid_t n, no; 
	int fb;
	fb = open("1.out", O_RDWR | O_CREAT | O_TRUNC, 0755);
	no = dup2(fb, STDOUT_FILENO);
	if(no < 0){
		perror("dup error\n");
	}
	n = fork();
	if(n < 0){
		perror("fork error\n");
	}
	else if(n == 0){
		printf("child \n");
		execlp("ps", "ps", "au", NULL);
	}
	else{
		printf("parent \n");
	}
	return 0;
}

