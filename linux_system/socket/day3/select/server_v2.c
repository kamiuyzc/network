#include "hyzc.h"
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/select.h>
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

	int clin_sock[FD_SETSIZE];
	for(i = 0;i < FD_SETSIZE;i++){
		clin_sock[i] = -1;
	}
	int maxfd, maxi = -1;
	int nready, j;
	fd_set allset, rset;


	lfd = Socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, (socklen_t)sizeof(opt_val));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	Bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	Listen(lfd ,1024);

	FD_ZERO(&allset);
	FD_SET(lfd, &allset);
	maxfd = lfd;

	while(1){
		rset = allset;
		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
		if(FD_ISSET(lfd, &rset)){
			cfd = Accept(lfd, (struct sockaddr *)&clin_addr, &clin_addr_len);
			y_getsockaddr(clin_addr, clin_ip, &clin_port);
			printf("client ip %s port %d connect\n", clin_ip, clin_port);
			FD_SET(cfd, &allset);
			if(cfd > maxfd){
				maxfd = cfd;
			}
			for(i = 0;i < FD_SETSIZE;i++){
				if(clin_sock[i] < 0){
					clin_sock[i] = cfd;
					break;
				}
			}
			if(i == FD_SETSIZE){
				exit(1);
			}
		    if(i > maxi){
		     	maxi = i;
			}

			if(--nready == 0){
				continue;
			}
		}
		for(j = 0;j <= maxi;j++){
			cfd = clin_sock[j];
            if (cfd < 0)
                continue;			
			if(!FD_ISSET(cfd, &rset)){
				continue;
			}

			bzero(wrbuf, BUFSIZ);
			bzero(rdbuf, BUFSIZ);
			res = Read(cfd, rdbuf, BUFSIZ);
			if(res == 0){
				close(cfd);
				FD_CLR(cfd, &allset);
				// if(cfd == maxfd){
				// 	maxfd--;
				// }
				clin_sock[j] = -1;
				continue;
			}
			else{
				//printf("read info: %s", rdbuf);
				for(i = 0;i < res;i++){
					wrbuf[i] = toupper(rdbuf[i]);
				}
				write(cfd, wrbuf, res);
				//printf("write info: %s", wrbuf);
			}
			if(--nready == 0){
				break;
			}
		}
	}
	return 0;
}

