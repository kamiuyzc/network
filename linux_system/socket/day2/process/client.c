#include "hyzc.h"
#include <arpa/inet.h>
#define IP "127.0.0.1"
#define PORT 8888

int main(int args, char *argv[])
{
    int cfd;
	int n;
	char buf[BUFSIZ]= {0};
	struct sockaddr_in serv_addr;


	cfd = Socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	inet_pton(AF_INET, IP, &serv_addr.sin_addr.s_addr); 
	serv_addr.sin_port = htons(PORT);

	Connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	n = 100;
	while(n--)
	{
		sprintf(buf, "hello %d \n", n);
		write(cfd, buf, strlen(buf));
		read(cfd, buf, 1024);
		printf("%s", buf);

		sleep(1);
	}

	close(cfd);

	return 0;
}

