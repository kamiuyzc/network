#include "link.h"

int main(void)
{
    struct node *head = listCreate();
	listPrint(head);
	insertNode(head, 5, 10);
	listPrint(head);
	removeNode(head, 6);
	listPrint(head);
	removeNodePro(head, 7);
	listPrint(head);
	listSort(head);
	listPrint(head);
	insertNodePro(head, 21);
	listPrint(head);
    reverse_link(head);
	listPrint(head);
	destroyLink(head);
	listPrint(head);
	return 0;
}

