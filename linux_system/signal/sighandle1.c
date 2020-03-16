#include "hyzc.h"
#include <signal.h>

void print_array(sigset_t *set)
{
	int i;
	printf("\n");
	for(i = 1;i < 32;i++){
		/*
		if(sigismember(set, i)){
			putchar('1');
		}
		else{
			putchar('0');
		}
		*/
		putchar(sigismember(set, i) + '0');
	}
}

int main(int args, char *argv[])
{
    sigset_t set, *p, pset, *q, oldset; 
    p = &set;
	q = &pset;
    
	print_array(p);
	sigfillset(p);
	print_array(p);
	/*
	sigemptyset(p);
	print_array(p);
	sigaddset(p, SIGINT);
	sigaddset(p, SIGHUP);
	print_array(p);
	sigdelset(p, SIGINT);
	print_array(p);
	*/
    sigprocmask(SIG_BLOCK, p, &oldset); 
	int i = 0;
	while(i++ < 10){
	    sigpending(q);
        print_array(q);
		sleep(1);
	}
	printf("over\n");
	sigemptyset(p);
	sigaddset(p, SIGHUP);
	sigprocmask(SIG_UNBLOCK, p, &oldset);
	printf("ok\n");

	while(1){
	    sigpending(q);
        print_array(q);
		sleep(1);
	}

	return 0;
}

