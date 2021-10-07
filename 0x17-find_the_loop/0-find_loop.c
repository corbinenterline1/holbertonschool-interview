#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Head node of linked list.
 * Return: Address of the node where loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head, *hare = head;

	while (turtle && hare && hare->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (turtle == hare)
		{
			turtle = head;
			while (hare)
			{
				if (turtle == hare)
					return (turtle);
			turtle = turtle->next;
			hare = hare->next;
			}
		}
	}
	return (NULL);
}
