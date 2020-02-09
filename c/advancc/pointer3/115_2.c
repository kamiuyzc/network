#include <stdio.h>
#include <string.h>

#define NUM(a) sizeof(a) / sizeof(*a)

void searchKeyTable(const char *table[10], const int size, const char *key, int *pos)
{
	int n = 1;
	int i = 0;
    for(i = 0;i < size;i++)
	{
		n = strcmp(table[i], key);
		if(n == 0)
		{
		    *pos = i + 1;
			break;
		}
	}
}
int main(int argc, char *argv[])
{
	const char *keywords[10] = {"while", "case", "static", "do"};
	int pos;
    char *key = "static";
	searchKeyTable(keywords, (int)(NUM(keywords)), key, &pos);
	printf("%d\n", pos);
    return 0;
}

