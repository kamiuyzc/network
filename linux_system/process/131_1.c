#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
    pid_t pid = fork(); 
	if(pid < 0){
        perror("fork error\n");
	}
	else if(pid == 0){
        printf("child fork process %d\n", getpid());
		while(1)
		{
			sleep(1);
			printf("child fork process %d\n", getpid());
		}
	}
	else{
        printf("father fork process %d\n", getpid());
		sleep(10);
	}
	return 0;
}

