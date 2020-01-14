#include <stdio.h>
#include <string.h>

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	char tmp[20] = {0};
    sscanf(keyvaluebuf, "%s = %s", tmp, valuebuf);
	printf("get key= '%s' value = '%s'\n", tmp, valuebuf);
	*valuebuflen = strlen(valuebuf);
}

int main(int argc, char *argv[])
{
    char a[100] = "key1     =     valude1";
	char key[20] = "key1";
	char value[20] = {0};
    int len;

	getKeyByValue(a, key, value, &len);

	printf("%s %s %d\n", key, value, len);
	
    return 0;
}

