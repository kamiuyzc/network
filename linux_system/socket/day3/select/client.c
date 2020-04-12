#include "hyzc.h"
#define PORT 8000 


int main(int args, char *argv[])
{
	char serv_ip[INET_ADDRSTRLEN];
	if (args < 2){
		strcpy(serv_ip, "127.0.0.2");
	}
	else{
		strcpy(serv_ip, argv[1]);
	}

    int cfd;

	struct sockaddr_in serv_addr;

	char rdbuf[BUFSIZ], wrbuf[BUFSIZ];
	int n = 5, res;

	cfd = Socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	inet_pton(AF_INET, serv_ip, &serv_addr.sin_addr.s_addr);	
	serv_addr.sin_port = ntohs(PORT);

	Connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	while (n--){
		bzero(rdbuf, BUFSIZ);
		bzero(wrbuf, BUFSIZ);
		sprintf(wrbuf, "hello %d\n", n);
		res = Write(cfd, wrbuf, strlen(wrbuf));
		Read(cfd, rdbuf, res);
		printf("read from server %s", rdbuf);
	}
	close(cfd);
	return 0;
}

