#include "lists.h"

/**
 * listint_lenreturn the number of elelments 
 * h linked list of type listint_t
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
