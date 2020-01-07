#include <stdio.h>
struct stu
{
    int num;
	char *name;
};
int main(int argc, char *argv[])
{
    struct stu a[3] = 
	{
		{1, "yzc"},
		{2, "puyol"},
		{3, "xcq"}
	};
	FILE *fp = fopen("1.out", "w");
	int ret = fwrite(a, sizeof(a[0]), 3, fp);
	printf("%d\n", ret);
	fclose(fp);


	fp = fopen("1.out", "r");
	struct stu b[3];
	int ret1;
	ret1 = fread(b, sizeof(b[0]), 3, fp);
	printf("%d\n", ret1);
	for(int i = 0; i < 3; i++)
	{
		printf("%d %s\n", b[i].num, b[i].name);
	}
    return 0;
}

