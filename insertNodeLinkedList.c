/* inserting a node at the beginning of a linkedList */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

void insert(struct node **head, int x);
void print(struct node *head);

int main()
{
	int n, i, x;
	struct node *head = NULL;
	printf("How many nodes to insert?\n");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		printf("Enter a number to insert\n");
		scanf("%d", &x);
		insert(&head, x);
		print(head);
	}
}

void insert(struct node **head, int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

void print(struct node *head)
{
	struct node* temp = head;
	printf("List is: ");
	while (temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
