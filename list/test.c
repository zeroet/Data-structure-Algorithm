#include <stdlib.h>
#include <stdio.h>

struct node
{
	char *data;
	struct node *next;
};	typedef struct node Node;

/*void	add_first(char *itme)
{
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	head = tmp;
}*/

int main()
{
	Node *head = (Node *)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node *q = (Node *)malloc(sizeof(Node));
	q->data = "Tuesdays";
	q->next = NULL;
	head->next = q;

	q = (Node *)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node *p = head;
	while (p)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
}
