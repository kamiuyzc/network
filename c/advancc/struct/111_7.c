#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Teacher
{
	char *name;
	char **student;
}Teacher;


void create_teacher(Teacher **p1, int num1, int num2)
{
    Teacher *teachers = (Teacher *)malloc(sizeof(Teacher) * num1);
	int i, j;
	for(i = 0;i < num1;i++)
	{
		teachers[i].name = malloc(30);
		sprintf(teachers[i].name, "teacher %d", i);
		teachers[i].student = (char **)malloc(sizeof(char *) * num2);
        for(j = 0;j < num2;j++)
		{
            teachers[i].student[j] = (char *)malloc(sizeof(char) * 30);
			sprintf(teachers[i].student[j], "student_%d", j);
		}
	}
	*p1 = teachers;
}

void print_teacher(Teacher *p1, int num1, int num2)
{
	int i, j;
    for(i = 0;i < num1;i++)
	{
		printf("teacher %s: ", p1[i].name);
		for(j = 0;j < num2;j++)
		{
            printf("%s ", p1[i].student[j]);
		}	
		printf("\n");
	}
}

void free_teacher(Teacher **p1, int num1, int num2)
{
    Teacher *tmp = *p1;
	int i, j;
	for(i = 0;i < num1;i++)
	{
		for(j = 0;j < num2;j++)
		{
			free(tmp[i].student[j]);
			tmp[i].student[j] = NULL;
		}
		free(tmp[i].student);
		tmp[i].student = NULL;
	}
	free(tmp);
	tmp = NULL;
}
int main(void)
{
	Teacher *p = NULL;
    create_teacher(&p, 3, 4); 
	print_teacher(p, 3, 4);
    free_teacher(&p, 3, 4); 
	return 0;
}

