#include "hyzc.h"
#include <arpa/inet.h>
#include <strings.h>
#include <pthread.h>
#include <ctype.h>

#define MAXLINE 8192
#define PORT 8888

struct s_info
{
	struct sockaddr_in cliaddr;
	int confd;
};

void * do_thread(void *args)
{
	int i;
	ssize_t res;
	char clin_ip[INET_ADDRSTRLEN] = {0};
	char buf[MAXLINE];
	bzero(buf, MAXLINE);
	struct s_info *ptr;
    ptr	= (struct s_info *)args;
	printf("client %s %d\n", inet_ntop(AF_INET, 
				                       &(ptr -> cliaddr).sin_addr.s_addr, 
									   clin_ip, 
									   sizeof(clin_ip)), 
			                 ntohs(ptr -> cliaddr.sin_port));

	while(1){
		res = Read(ptr -> confd, buf, MAXLINE);
		if(res == 0){
			printf("client close %d\n", ptr -> confd);
			break;
		}
		for(i = 0;i < res;i++){
			buf[i] = toupper(buf[i]);
		}
		printf("%s", buf);
		write(ptr -> confd, buf, res);
	}

	Close(ptr -> confd);
	return NULL;
}
int main(int args, char *argv[])
{
    int lfd, cfd;
	int i;
	struct sockaddr_in serv_addr, clin_addr;
	struct s_info socklist[256];
	bzero(socklist, sizeof(socklist));
	socklen_t clinaddr_len;
	clinaddr_len = sizeof(clin_addr);

	lfd = Socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	Bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	Listen(lfd, 256);
    pthread_t tid;
	while(1){
       cfd = Accept(lfd, (struct sockaddr *)&clin_addr, &clinaddr_len); 
	   socklist[i].cliaddr = clin_addr;
	   socklist[i].confd = cfd;
	   pthread_create(&tid, NULL, do_thread, (void *)&socklist[i]);
	   pthread_detach(tid);
	   i++;
	}

	

	return 0;
}

