#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void write_data(const char *data, char *filename)
{
	FILE *fp = fopen(filename, "w");
	fputs(data, fp);
	fclose(fp);
}

int operate(int num1, int num2, char op)
{
    int result;
	switch(op)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		default:
			result = 0;
	}
	return result;
}

void write_file()
{
    srand((unsigned int)time(NULL));    
	char a[100];
	char data[1024] = {0};
	char op[] = {'+', '-', '*', '/'};
    for(int i = 0;i < 4;i++)
	{
        sprintf(a, "%d%c%d=\n", rand()%100, op[i], rand()%100);
		strcat(data, a);
	}
	write_data(data, "1.out");
}

void read_file()
{
	char tmp[100] = {0};
	char wtmp[100] = {0};
	char data[1024] = {0};
	FILE *fp = fopen("1.out", "r");
	int num1, num2;
	char op;
	while(1)
	{
        fgets(tmp, sizeof(tmp), fp);
		if (feof(fp))
		{
			break;
		}
		sscanf(tmp, "%d%c%d=\n", &num1, &op, &num2);
	    sprintf(wtmp, "%d%c%d=%d\n", num1, op, num2, operate(num1, num2, op));	
		strcat(data, wtmp);
	}
    //printf("result:%s", data);
    fclose(fp);	
	write_data(data, "2.out");

}

int main(int argc, char *argv[])
{
    write_file(); 
    read_file(); 
    return 0;
}

