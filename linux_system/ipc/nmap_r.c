#include "hyzc.h"
#include <sys/mman.h>

struct student{
	int id;
	char name[50];
	int age;
};


int main(int args, char *argv[])
{
	struct student *p = NULL;
    int fd, res ,len;

	fd = open("1.out", O_RDONLY);
    sys_err(fd, "open error\n", 1);	
    len = lseek(fd, 0, SEEK_END);

	p = (struct student *)mmap(NULL, len, PROT_READ, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		perror("mmap error\n");
	}

	close(fd);

	while(1){
		printf("student id %d name %s age %d\n", p -> id, p -> name, p -> age);
		usleep(500000);
	}
	res = munmap(p, len);
	sys_err(res, "munmap error\n", 2);



	return 0;
}

