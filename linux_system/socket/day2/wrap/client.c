#include "hyzc.h"
#include <arpa/inet.h>
#include <stdio.h>

#define PORT 8000
#define NUM 1024 

int main(int args, char *argv[])
{
	if (args < 2){
		printf("input ip address\n");
		exit(0);
	}
	char *sip = argv[1];
    int res;
	int cfd;
	char buf[1024] = {0};
	memset(buf, 'a', NUM - 1);
	struct sockaddr_in serv_addr;

	cfd = Socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	inet_pton(AF_INET, sip, &serv_addr.sin_addr.s_addr);

	Connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	while(1){
	    res = Writen(cfd, buf, 1024);
	    usleep(1000000);
	}
	Read(cfd, buf, res);
	printf("%s", buf);
	Close(cfd);
	return 0;
}

