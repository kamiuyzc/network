#include <stdio.h>

struct stu
{
	int id;
	char *name;
};

int main(int argc, char *argv[])
{
	struct stu tmp, b[3];
	struct stu a[3] = 
	{
		{1, "yzc"},
		{2, "xzq"},
		{3, "puyol"}
	};
    FILE *fp = fopen("1.out", "w");
	fwrite(a, sizeof(a[0]), 3, fp);
	fclose(fp);

	fp = fopen("1.out", "r");
	int ret = fseek(fp, sizeof(a[0]) * 2, SEEK_SET);
	printf("fseek return value %d\n", ret);
	ret = ftell(fp);
	printf("ftell return value %d\n", ret);

	ret = fread(&tmp, sizeof(tmp), 1, fp);
	printf("fread return value %d\n", ret);
	printf("temp value %s %d\n", tmp.name, tmp.id);

    rewind(fp);

	ret = ftell(fp);
	printf("ftell return value %d\n", ret);

	ret = fread(b, sizeof(b[0]), 3, fp);
	printf("fread return value %d\n", ret);
	for(int i = 0;i < 3;i++)
	{
		printf("%s %d\n", b[i].name, b[i].id);
	}
    return 0;
}

