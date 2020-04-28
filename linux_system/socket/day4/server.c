#include "hyzc.h"
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/epoll.h>
#define PORT 8000
#define OPEN_MAX 5000 

int main(int args, char *argv[])
{
    int lfd, cfd, tmpsock;
	int opt_val = 1;

	struct sockaddr_in serv_addr, clin_addr;
	socklen_t clin_addr_len = sizeof(clin_addr);
	char clin_ip[INET_ADDRSTRLEN];
	int clin_port;

	int  i, j, n;
	ssize_t res;
	char wrbuf[BUFSIZ], rdbuf[BUFSIZ];
    
	lfd = Socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, (socklen_t)sizeof(opt_val));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

    Bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    Listen(lfd ,1024);
    int nready, efd;
	struct epoll_event tep, ep[OPEN_MAX];

	efd = epoll_create(OPEN_MAX);
	y_sys_err(efd, "creat_epoo", 1);

	tep.events = EPOLLIN;
	tep.data.fd = lfd;
	res = epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &tep);
	y_sys_err(res, "epoll ctrl", 1);

	while(1){
		nready = epoll_wait(efd, ep, OPEN_MAX, -1);
	    y_sys_err(nready, "epoll wait", 1);

		for(j = 0;j < nready;j++){
			if(!(ep[j].events & EPOLLIN)){
				continue;
			}
			tmpsock = ep[j].data.fd;
			if(tmpsock == lfd){
		        cfd = Accept(lfd, (struct sockaddr *)&clin_addr, &clin_addr_len);
		        y_getsockaddr(clin_addr, clin_ip, &clin_port);
		        printf("client ip %s port %d connect\n", clin_ip, clin_port);
				tep.events = EPOLLIN;
				tep.data.fd = cfd;
	            res = epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &tep);
	            y_sys_err(res, "epoll ctrl", 1);
			}
			else{
			    bzero(wrbuf, BUFSIZ);
			    bzero(rdbuf, BUFSIZ);
			    n = Read(tmpsock, rdbuf, BUFSIZ);
			    if(n == 0){
					close(tmpsock);
					res = epoll_ctl(efd, EPOLL_CTL_DEL, tmpsock, NULL);
					printf("quit sock \n");
					continue;
			    }
			    if(n == -1){
					close(tmpsock);
					res = epoll_ctl(efd, EPOLL_CTL_DEL, tmpsock, NULL);
					printf("quit sock \n");
					continue;
			    }
			    for(i = 0;i < n;i++){
			    	wrbuf[i] = toupper(rdbuf[i]);
			    }
			    write(tmpsock, wrbuf, res);
			    printf("write info: %s", wrbuf);
			}
		}
	}
	return 0;
}

