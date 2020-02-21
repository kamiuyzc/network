#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int id;
	char name[10];
	struct node *next;
};

void init_static_link()
{
	struct node n1 = {1, "y1", NULL}; 
	struct node n2 = {2, "y2", NULL}; 
	struct node n3 = {3, "y3", NULL}; 
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;
	struct node *p = &n1;
	while(p)
	{
		printf("%s %d\n", p -> name, p -> id);
		p = p -> next;
	}
}

struct node * init_dynamic_link()
{
	struct node *head, *curnode, *pnew = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	head -> id = 0;
	sprintf(head -> name, "y1");
	head = curnode;
	int data;
	while(1)
	{
		printf("input a num:");
		scanf("%d", &data); 
		if(data == -1)
		{
			break;
		}
		else
		{
			pnew = (struct node *)malloc(sizeof(struct node));
			pnew -> id = data;
			sprintf(pnew -> name, "std_%d", data * 2 + 1);
			pnew -> next = NULL;
			curnode -> next = pnew;
			curnode = pnew;
		}
	}
	return head;
}

void list_dynamic_list(struct node *head)
{
    struct node *tmp;
	tmp = head -> next;
	while(tmp)
	{
		printf("%d -> ", tmp -> id);
		tmp = tmp -> next;
	}
}

int main(int argc, char *argv[])
{
	//init_static_link(); 
	struct node *head;
	head = init_dynamic_link(); 
	list_dynamic_list(head);
	return 0;
}

