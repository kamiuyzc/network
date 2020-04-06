#include "hyzc.h"
#include <arpa/inet.h>
#include <ctype.h>
#define PORT 8000

int main(int args, char *argv[])
{
    int sfd, cfd;
	int res, i;
	struct sockaddr_in serv_addr, clit_addr;
	char buf[1024 * 5] = {0};
	char clit_ip[20] = {0};

	sfd = Socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr  = htonl(INADDR_ANY);
	Bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	Listen(sfd, 512);

	socklen_t clit_addr_len;
	clit_addr_len = sizeof(clit_addr);
	while(1){
		cfd = Accept(sfd, (struct sockaddr *)&clit_addr, &clit_addr_len);
		printf("client %d %s\n", ntohs(clit_addr.sin_port)
								,inet_ntop(AF_INET, &clit_addr.sin_addr.s_addr, clit_ip, sizeof(clit_ip)));
		memset(buf, 0, BUFSIZ);
		while(1){
			//memset(buf, 0, 10);
		    res = Readn(cfd, buf, 1024 * 5);
			sleep(1);
			printf("la %s %d\n", buf,res);
		}
		/*
		for(i = 0;i < res;i++){
			buf[i] = toupper(buf[i]);
		}
		Write(cfd, buf, res);
		*/
		Close(cfd);
	}
	Close(sfd);
	return 0;
}

