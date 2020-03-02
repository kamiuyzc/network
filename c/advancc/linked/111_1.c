#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int id;
	char name[10];
	struct node *next;
};
void empty_link(struct node *head)
{
	struct node *tmp;
	struct node *cur = head -> next;
    while(cur)
	{
		tmp = cur -> next;
		free(cur);
		cur = tmp;
	}
	head -> next = NULL;
}

void delete_node(struct node *head)
{
	printf("input delete val: ");
	int val;
	scanf("%d", &val);
	struct node *pre = head;
	struct node *cur = head -> next;
	while(cur)
	{
		if(cur -> id == val)
		{
			break;
		}
		pre = cur;
		cur = cur -> next;
	}
	if(cur == NULL)
	{
		printf("do not exist");
	}
	else
	{
		pre -> next = cur -> next;
	}
}

void insert_static_link(struct node *head, int oldval)
{
	struct node *pre = head;
	struct node *cur = head -> next;
	int new_val;
	while(cur)
	{
		if(cur -> id == oldval)
		{
			break;
		}
		pre = cur;
		cur = cur -> next;
	}
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("input insert num: ");
	scanf("%d", &new_val);
	new -> id = new_val;
	sprintf(new -> name, "stu_%d", new_val);
	new -> next = cur;
	pre-> next = new;
}

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
	printf("\n");
}

int main(int argc, char *argv[])
{
	//init_static_link(); 
	struct node *head;
	head = init_dynamic_link(); 
	list_dynamic_list(head);
	//delete_node(head);
	empty_link(head);
	list_dynamic_list(head);
	return 0;
}

