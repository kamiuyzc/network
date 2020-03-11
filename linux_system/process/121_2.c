#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int args, char *argv[])
{
    char *ar[] = {"ls", "-a", "-laaaaaaaaaaaaaaaaaaaaa", NULL};
	printf("%ld\n", sizeof(ar));
    pid_t pt = fork();
	if(pt < 0){
		perror("fork error\n");
	}
	else if(pt == 0){
		printf("child process\n");
		execvp("ls", ar);
	}
	else{
		printf("parent process\n");
	}
	printf("end process\n");
	return 0;
}

