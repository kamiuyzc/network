#include "hyzc.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 8888

int main(int args, char *argv[])
{
	char ip[100] = {0};
    strcpy(ip, argv[1]);
	int lfd, cfd;
	int res;
    socklen_t c_len;

	char buf[BUFSIZ] = {0};
	char s_addr[1024] = {0};
	struct sockaddr_in ssockaddr, csockaddr;

	lfd = socket(AF_INET, SOCK_STREAM,0);
	sys_err(lfd, "sock create", 1);

	ssockaddr.sin_family = AF_INET;
	ssockaddr.sin_port = htons(PORT);
	inet_pton(AF_INET, ip,(void *)&ssockaddr.sin_addr.s_addr);
	res = bind(lfd, (struct sockaddr *)&ssockaddr, sizeof(ssockaddr));
	sys_err(res, "bind", 2);

	res = listen(lfd, 512);
	sys_err(res, "listen", 2);

	c_len = sizeof(csockaddr);
	cfd = accept(lfd, (struct sockaddr *)&csockaddr, &c_len);
	printf("connect ip %d %s %d\n", ntohs(csockaddr.sin_port), 
									inet_ntop(AF_INET, (void *)&csockaddr.sin_addr.s_addr, s_addr, sizeof(s_addr)),
									c_len);

	sys_err(res, "accept", 2);
	
	int n = 5, i;
	while(n--){
		res = read(cfd, buf, BUFSIZ);
		sys_err(res, "read", 2);
		write(STDOUT_FILENO, buf, res);
		for(i = 0;i < 5;i++){
			buf[i] = toupper(buf[i]);
		}
		write(cfd, buf, res);
	}
	close(cfd);
	close(lfd);
	return 0;
}

