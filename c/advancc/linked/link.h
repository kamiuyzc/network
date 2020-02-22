#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int id;
	struct node *next;
}

struct node * listCreate();

void listPrint(struct node *head);

void insertNode(struct node *head, int x, int y);

void removeNode(struct node *head, int x);

void destroyLink(struct node *head);
