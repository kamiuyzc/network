#include <stdio.h>
#include <string.h>

typedef struct _Student
{
    char name[50];
	int age;
}S;

void my_write(char *path)
{
	int i, size;
	S a[3];
	for(i = 0;i < 3;i++)
	{
        sprintf(a[i].name, "stu_%d", i);
		a[i].age = i * 2 + 1;
	}
    FILE *fp = fopen(path, "w");
	size = sizeof(S);
	fwrite(a, size, 3, fp);
	fclose(fp);
}

void my_read(char *path)
{
	int i, size;
	size = sizeof(S);
    FILE *fp = fopen(path, "r");
	S a[3];
	memset(a, 0, 3 * size);
	fread(a, size, 3, fp);
	for(i = 0;i < 3;i++)
	{
        printf("result:%s %d\n", a[i].name, a[i].age);
	}
	fclose(fp);
}

void my_seek_read(char *path)
{
	int size;
	size = sizeof(S);
	S a;
    FILE *fp = fopen(path, "r");
    fseek(fp, size, SEEK_SET);
	fread(&a, size, 1, fp);
    printf("result:%s %d\n", a.name, a.age);
    fseek(fp, 0 - 3 * size, SEEK_END);
	fread(&a, size, 1, fp);
    printf("result:%s %d\n", a.name, a.age);
    fseek(fp, 1 * size, SEEK_CUR);
	fread(&a, size, 1, fp);
    printf("result:%s %d\n", a.name, a.age);
	int n = ftell(fp);
	printf("%d\n", n);
	fclose(fp);
}

int main(void)
{
	char *path = "4.txt";
    my_write(path); 
    //my_read(path); 
    my_seek_read(path); 
	return 0;
}

