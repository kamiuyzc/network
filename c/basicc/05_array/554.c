#include <stdio.h>

int main(void)
{
    char abc[] = "abcd";    
	char def[] = "1234";
	char result[100] = {'0'};
	int i = 0;
	int j = 0;

	while (abc[i] != '\0')
	{
		result[i] = abc[i];
		i++;
	}

	while (def[j] != '\0')
	{
		result[i] = def[j];
		i++;
		j++;
	}
	printf("the result is : %s", result);
    return 0;
}

