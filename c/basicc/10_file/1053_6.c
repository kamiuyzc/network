#include <stdio.h>

int main(int argc, char *argv[])
{
	rename("3.out", "1.out");
    remove("1.out");
    return 0;
}

