#include <stdio.h>
enum test
{
    yellow=1, red, blue, green,	
};
int main(int argc, char *argv[])
{
    printf("%d %d %d %d\n",yellow ,red, blue, green); 
	enum test t;
	t = blue;
	printf("%d\n", t);
    return 0;
}

