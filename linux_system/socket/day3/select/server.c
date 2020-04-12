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

	fd_set allset, readset;
	int ret, maxfd, cfd_i;


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
		readset = allset;
		printf("start select\n");
		y_get_time();
		ret = select(maxfd + 1, &readset, NULL, NULL, NULL);
		y_get_time();
		y_sys_err(ret, "select", 1);

		printf("end select %d\n", ret);
		if(FD_ISSET(lfd, &readset)){
			cfd = Accept(lfd, (struct sockaddr *)&clin_addr, &clin_addr_len);
			printf("lfd %d create cfd %d\n", lfd, cfd_i);			
			y_getsockaddr(clin_addr, clin_ip, &clin_port);
			//printf("client ip %s port %d connect\n", clin_ip, clin_port);
			FD_SET(cfd, &allset);
			if(cfd > maxfd){
				maxfd = cfd;
				printf("maxfd %d\n", maxfd);
			}
			if(--ret == 0){
				continue;
			}
		}
        
		for(cfd_i = lfd + 1;cfd_i <= maxfd;cfd_i++){
			if(!FD_ISSET(cfd_i, &readset)){
				continue;
			}
			printf("cfd %d read\n", cfd_i);
			bzero(wrbuf, BUFSIZ);
			bzero(rdbuf, BUFSIZ);
			res = Read(cfd_i, rdbuf, BUFSIZ);
			if(res == 0){
			    Close(cfd_i);
			    FD_CLR(cfd_i, &allset);
			    //printf("client ip %s port %d close\n", clin_ip, clin_port);
			}
			else{
				//printf("read info: %s", rdbuf);
				for(i = 0;i < res;i++){
					wrbuf[i] = toupper(rdbuf[i]);
				}
				write(cfd_i, wrbuf, res);
				printf("write info: %s\n", wrbuf);
			}
		}
	}
	close(lfd);
	return 0;
}

