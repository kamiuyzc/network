#include <stdio.h>
#include <string.h>
#include <ctype.h>

int myTrim(char *src, char *buf)
{
	int len = strlen(src);
	char *dst = src + len -1;
	while(isspace(*src))
	{
        src++;
	}

	printf("char *dst %c\n", *dst);
	while(isspace(*dst))
	{
        dst--;
	}

	strncpy(buf, src, dst - src + 1);
    return 0;
}

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
   char *p;
   p = keyvaluebuf;
   char *ret = strstr(p, keybuf);
   if(!ret) 
   {
        return -1;
   }
   p = ret + strlen(keybuf);


   ret = strstr(p, "=");
   if(!ret) 
   {
        return -2;
   }
   p = ret + strlen("=");

   char a[30] = {0};
   myTrim(p, a);
   *valuebuflen = strlen(a);
   strcpy(valuebuf, a); 
   
}

int main(int argc, char *argv[])
{
    char *a = "   key1     =     viasdfasf    ";
	char key[20] = "key1";
	char value[20] = {0};
    int len;

	getKeyByValue(a, key, value, &len);

	printf("key:'%s' value:'%s' n:'%d'\n", key, value, len);
	
    return 0;
}

