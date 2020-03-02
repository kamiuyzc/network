#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int replaceSubStr(char *src, char **dst, char *sub, char *new_sub)
{
    if(src == NULL || dst == NULL || sub == NULL || new_sub == NULL)
    {
        return -1; 
    }
    char *p = src;
	char tmp[100];
	int len_sub = strlen(sub);
	int len_sub_new = strlen(new_sub);
	while(*p != '\0')
	{
		p = strstr(p, sub);
        if(src != p)        
		{
            strncpy(tmp, p, );
		}
	}
    return 0;

}
int main(int argc, char *argv[])
{   
    char *src = "abcd1111abcd2222abcdqqqqqq";
    char *buf = NULL;
    int rep = replaceSubStr(src, &buf, "abcd", "dcba");
    if (rep != 0)
    {   
        printf("error %d\n", rep);
        return rep;
    }
    printf("result is %s", %buf);
	if(buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
    return 0;
}

