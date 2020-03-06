#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

void get_file(char *path)
{
	struct stat st;
	DIR *dp;
	int n;
	n = lstat(path, &st);
	char *p = (char *)malloc(256 * sizeof(char));
	memset(p, 0, 256);
	if(n == -1)
	{
		perror("lstat error");
	}
	if(S_ISDIR(st.st_mode)){
		dp = opendir(path);
		struct dirent *dr;
		while((dr = readdir(dp)) != NULL)
		{
			if(strcmp(dr->d_name, "..") != 0 && strcmp(dr->d_name, ".") != 0)
			{
				//strcpy(p, path);
				//p[strlen(path)] = '/';
				//strcpy(p + strlen(path) + 1, dr -> d_name);
				sprintf(p, "%s/%s", path, dr -> d_name);
				get_file(p);	
			}
		}
		closedir(dp);
	}
	else{
		printf("%s %ld\n", path, st.st_size);
	}
}

int main(int args, char *argv[])
{
	get_file("/home/yangzhengchu/git/network/linux_system/day4"); 
	return 0;
}

