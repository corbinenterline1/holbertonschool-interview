#include "lists.h"
/**
 * is_palindrome - Checks if singly linked list is a palindrome.
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if palindrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
	listint_t *s; /* Start node pointer */
	listint_t *m; /* mid node pointer */
	listint_t *r; /* reversed list node pointer */
	int h, i, c = 1; /* half, index, count */

	if (*head == NULL)
		return (1);
	s = *head;
	m = *head;
	while (m->next != NULL)
	{
		m = m->next;
		c++;
	}
	h = c / 2;
	m = *head;
	for (i = 1; i < h; i++)
		m = m->next;
	r = reversal(m);
	while (s != NULL && r != NULL)
	{
		if (s->n != r->n)
			return (0);
		s = s->next;
		r = r->next;
	}
	return (1);

}

/**
 * reversal - reverses linked list
 * @head: pointer to first node of listint_t list
 * Return: address of new element
 */
listint_t *reversal(listint_t *head)
{
	listint_t *current = head;
	listint_t *prevNode = NULL, *nextNode = NULL;

	while (current != NULL)
	{
		nextNode = current->next;
		current->next = prevNode;
		prevNode = current;
		current = nextNode;
	}
	return (revNode);
}
