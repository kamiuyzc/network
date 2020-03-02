#include "link.h"

struct node * listCreate()
{
    struct node *head, *node, *newnode;
	int data;
	head = (struct node *)malloc(sizeof(struct node));
	node = head;
	int a[] = {3, 6, 5, 5, 30, 7, 9, 20, 6, 8, -1};
	int i = 0;
	while(1)
	{
		printf("Input a num: ");
		scanf("%d", &data);
		//data = a[i++];
		if(data == -1)
		{
			break;
		}
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode -> id = data;
		newnode -> next = NULL;
		node -> next = newnode;
		node = newnode;
	}
	return head;
}

void listPrint(struct node *head)
{
    struct node *node = head;
	node = head -> next;
	while(node)
	{
		printf(" %d -> ", node -> id);
		node = node -> next;
	}
	printf("\n");
}

void insertNode(struct node *head, int x, int y)
{
    struct node *cur, *pre, *newnode;
	pre = head;
	cur = head -> next;
	while(cur)
	{
		if(cur -> id == x)
		{
			break;
		}
		pre = cur;
		cur = cur -> next;
	}
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> id = y;
	pre -> next = newnode;
	newnode -> next = cur;
}

void removeNode(struct node *head, int x)
{
    struct node *prev, *cur;
	cur = head -> next;
	prev = head;
	while(cur)
	{
        if(cur -> id == x)
		{
			break;
		}
		prev = cur;
		cur = cur -> next;
	}
	if(cur == NULL)
	{
		printf("delete ele exist");
	}
	prev -> next = cur -> next;
}

void destroyLink(struct node *head)
{
    struct node *tmp, *cur;
	cur = head -> next;
    while(cur)	
	{
		tmp = cur-> next;
		free(cur);
		cur = tmp;
	}
	head -> next = NULL;
}

void removeNodePro(struct node *head, int x)
{
	struct node *prev, *cur;
	prev = head;
	cur = head -> next;
	while(cur)
	{
        if(x == cur -> id)
		{
			prev -> next = cur -> next;
		}
		else
		{
			prev = cur;
		}
		cur = cur -> next;
	}
}

void listSort(struct node *head)
{
    struct node *curi, *curj, *tmp, *curo;
	tmp = (struct node *)malloc(sizeof(struct node));
	curi = head -> next;
	int i = 0;
	int j = 0;
	while(curi -> next)
	{
		curj = curi -> next;
		while(curj)
		{
		    if(curi -> id > curj -> id)	
			{
                *tmp =  *curi;
				*curi = *curj;
				*curj = *tmp;
				tmp -> next = curi -> next;
				curi -> next = curj -> next;
				curj -> next = tmp -> next;
			}
			curj = curj -> next;
		}
		curi = curi -> next;
	}
}

void insertNodePro(struct node *head, int x)
{
    struct node *cur, *pre, *newnode;
	pre = head;
	cur = head -> next;
	while(cur)
	{
		if(cur -> id > x)
		{
			break;
		}
		pre = cur;
		cur = cur -> next;
	}
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> id = x;
	pre -> next = newnode;
	newnode -> next =cur;
}

void reverse_link(struct node *head)
{
    struct node *cur, *pre, *tmp;
	//pre = head;
	cur = head -> next;
	pre = NULL;
    while(cur)
	{
        tmp = cur -> next;
		cur -> next = pre;
		pre = cur;
		cur = tmp;
	}
	head -> next = pre;

}
