#include "lists.h"

/**
 * insert_nodeint_at_index  insert  new node in  linked list
 * head: pointer first node in list
 * idxs: index where the new node is added
 * in: data to insert in the new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idxs, int in)
{
	unsigned int i;
	listint_t *news;
	listint_t *temp = *head;

	news = malloc(sizeof(listint_t));
	if (!news || !head)
		return (NULL);

	news->n = in;
	news->next = NULL;

	if (idxs == 0)
	{
		news->next = *head;
		*head = news;
		return (news);
	}

	for (i = 0; temp && i<idxs; i++)
	{
		if (i == idxs - 1)
		{
			news->next = temp->next;
			temp->next = news;
			return (news);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
