#include "hyzc.h"
#include <strings.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <signal.h>
#include <sys/wait.h>
#define IP 127.0.0.1
#define PORT 8888

void do_sigchild(int signum)
{
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int args, char *argv[])
{
	int lfd, cfd;
	struct sockaddr_in serv_addr, clin_addr;
	char buf[BUFSIZ] = {0};
	char clinip[INET_ADDRSTRLEN];
	int ret, i;
	pid_t pid;
	socklen_t clinaddr_len;
	clinaddr_len = sizeof(clin_addr);

	lfd = Socket(AF_INET, SOCK_STREAM, 0);

	int opt_val = 1;
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val));	

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	//inet_pton(AF_INET, IP, &serv_addr.sin_addr.s_addr);
	serv_addr.sin_port = htons(PORT);

	Bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

	Listen(lfd, 512);

	struct sigaction act, oldact;
	act.sa_handler = do_sigchild;
	sigemptyset(&act.sa_mask);
	act.sa_flags= 0;
	ret = sigaction(SIGCHLD, &act, &oldact);
	y_sys_err(ret, "sigaction", 1);


	while(1){
		cfd = Accept(lfd, (struct sockaddr *)&clin_addr, &clinaddr_len);
		printf("client ip : %s\tport : %d\n", inet_ntop(AF_INET, 
					&clin_addr.sin_addr.s_addr,
					clinip,
					sizeof(clinip)
					), 
				ntohs(clin_addr.sin_port));
		pid = fork();
		y_sys_err(pid, "fork", 1);	
		if(pid == 0){
			close(lfd);
			break;
		}
		else{
			close(cfd);

			continue;
		}
	}

	if(pid == 0){
		for(;;){
			ret = Read(cfd, buf, BUFSIZ);
			if(ret == 0){
				close(cfd);
				exit(1);
			}
			for(i = 0;i < ret;i++){
				buf[i] = toupper(buf[i]);
			}
			write(cfd, buf, ret);
			write(STDOUT_FILENO, buf, ret);
		}
	}
	return 0;
}

