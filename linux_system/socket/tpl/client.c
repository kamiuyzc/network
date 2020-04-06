#include "hyzc.h"
#include <arpa/inet.h>
#include <stdio.h>

#define PORT 8000
#define NUM 1024 
#define IP "127.0.0.2"

int main(int args, char *argv[])
{
	char *sip = argv[1];
    int cfd, res;
	char buf[BUFSIZ] = {0};
	struct sockaddr_in serv_addr;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	inet_pton(AF_INET, IP, &serv_addr.sin_addr.s_addr);
	cfd = Socket(AF_INET, SOCK_STREAM, 0);

	Connect(cfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	strcpy(buf, "tcpdump -i lo -ne -s 0 icmp -w /tmp/1.pcap\n");

    FILE	


	res = Writen(cfd, buf, BUFSIZ);
	
	Read(cfd, buf, res);

	Close(cfd);

	return 0;
}

