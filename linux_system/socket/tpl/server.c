#include "hyzc.h"
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#define PORT 8000


int main(int args, char *argv[])
{
    int lfd, cfd;
	int opt_val = 1;

	struct sockaddr_in serv_addr, clin_addr;
	socklen_t clin_addr_len = sizeof(clin_addr);
	char clin_ip[INET_ADDRSTRLEN];
	int clin_port;

	int  i;
	ssize_t res;
	char wrbuf[BUFSIZ], rdbuf[BUFSIZ];
    
	lfd = Socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, (socklen_t)sizeof(opt_val));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

    Bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    Listen(lfd ,1024);

	while(1){
		cfd = Accept(lfd, (struct sockaddr *)&clin_addr, &clin_addr_len);
		y_getsockaddr(clin_addr, clin_ip, &clin_port);
		printf("client ip %s port %d connect\n", clin_ip, clin_port);
        
		while(1){
			bzero(wrbuf, BUFSIZ);
			bzero(rdbuf, BUFSIZ);
			res = Read(cfd, rdbuf, BUFSIZ);
			if(res == 0){
				break;
			}
			printf("read info: %s", rdbuf);
			for(i = 0;i < res;i++){
				wrbuf[i] = toupper(rdbuf[i]);
			}
			write(cfd, wrbuf, res);
			printf("write info: %s", wrbuf);
		}
		close(cfd);
		printf("client ip %s port %d close\n", clin_ip, clin_port);
	}
	return 0;
}

