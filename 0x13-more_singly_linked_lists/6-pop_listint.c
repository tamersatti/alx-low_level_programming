#include "lists.h"

/**
 * pop_listint delete head node of  linked list
 * head: pointer first element in the linked list
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int numb;

	if (!head || !*head)
		return (0);

	numb = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (numb);
}
