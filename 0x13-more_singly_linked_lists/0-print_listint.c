#include "lists.h"

/**
 * print_listint - prints all the elements
 * h link list of the type listint_t
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
