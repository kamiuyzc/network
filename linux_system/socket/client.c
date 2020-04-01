#include "hyzc.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 8888

int main(int args, char *argv[])
{
    int res, sfd; 
	char ip[100]; 
	strcpy(ip, argv[1]);

	struct sockaddr_in serveraddr;
	char buf[BUFSIZ] = {0};


	sfd = socket(AF_INET, SOCK_STREAM, 0);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(PORT);
	inet_pton(AF_INET, ip,(void *)&serveraddr.sin_addr.s_addr);

	res = connect(sfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    sys_err(res, "connect", 1);

    int n = 5;
	while(n--){
		res = write(sfd, "hello\n", 6);
        sys_err(res, "write", 1);
		res = read(sfd, buf, res);
        sys_err(res, "read", 1);
		printf("%s", buf);
		usleep(100000);
	}
	close(sfd);
	return 0;
}

