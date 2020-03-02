#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *str1 = "hello"; 
	printf("hello pointer %p\n", "hello");
	printf("pointer method%p\n", str1);
    //strcpy(str1,"abc" );指针指向常量字符串的地址,不能修改.

    char str3[10];
	strcpy(str3,"abc" );
    printf("str3 is %s\n", str3);    

	char str2[] = "hello";//该步骤等于11到12行.先定义一个字符常量,再拷贝到str2中
    printf("str2 is %s\n", str2);    

    return 0;
}

