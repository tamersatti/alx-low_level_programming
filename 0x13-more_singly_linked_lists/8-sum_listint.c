#include "lists.h"

/**
 * sum_listint  calculates sum of all data in listint_t list
 * @head: first node in the linked list
  */
int sum_listint(listint_t *head)
{
	int suma = 0;
	listint_t *temp = head;

	while (temp)
	{
		suma += temp->n;
		temp = temp->next;
	}

	return (suma);
}
