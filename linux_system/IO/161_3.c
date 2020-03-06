#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 

int main(int args, char *argv[])
{
	int fb = open("2.out", O_RDWR | O_TRUNC | O_CREAT, 0755);
	if(fb < 0){
		perror("open error:");
	}

    int fbnew = fcntl(fb, F_DUPFD, 8); 
	printf("%d\n", fbnew);
	write(fbnew, "abc", 3);
	close(fbnew);

	return 0;
}
	
