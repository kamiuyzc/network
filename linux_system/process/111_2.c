#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
	int i;
	for(i = 0;i < 5;i++){
		if(fork() == 0){
			break;
		}
	}

	if(i == 5){
		sleep(3);
		printf("father process %d\n", getpid());
	}
	else {
		sleep(1);
		printf("child process %d\n", getpid());
		return 0;
	}
}

