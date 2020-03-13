#include "hyzc.h"
#include <sys/mman.h>

struct student{
	int id;
	char name[50];
	int age;
};


int main(int args, char *argv[])
{
	struct student st1 = {1, "def", 10};
	struct student *p = NULL;
    int fd, res ,len;

	fd = open("1.out", O_RDWR | O_CREAT | O_TRUNC, 0755);
    sys_err(fd, "open error\n", 1);	

    len = sizeof(struct student); 
	ftruncate(fd, len);

	p = (struct student *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED){
		perror("mmap error\n");
	}

	close(fd);
	while(1){
		memcpy(p, &st1, len);
		st1.id++;
		sleep(1);
	}
	res = munmap(p, len);
	sys_err(res, "munmap error\n", 2);



	return 0;
}

