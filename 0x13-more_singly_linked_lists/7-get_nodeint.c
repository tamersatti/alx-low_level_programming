#include "lists.h"

/**
 * get_nodeint_at_index return  node at certain index in linked list
 * head first node in the linked list
 * index index of the node return
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int in = 0;
	listint_t *temp = head;

	while (temp && in < index)
	{
		temp = temp->next;
		in++;
	}

	return (temp ? temp : NULL);
}
