#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	char *name;
	int id;
	int name_len;
};

int main(int argc, char *argv[])
{
    struct stu s, t;
	s.id = 3;
	s.name_len = strlen("mike");
	s.name = (char *)malloc(s.name_len + 1);
	strcpy(s.name, "mike");
	FILE *fp = fopen("1.out", "w");
	fwrite(&s, sizeof(struct stu), 1, fp);
	fclose(fp);
	FILE *fp1 = fopen("1.out", "r");
	fread(&t, sizeof(struct stu), 1, fp);
	printf("%d\n", t.id);
	printf("%s\n", t.name);
	printf("%d\n", t.name_len);
	fclose(fp1);
    return 0;
}

