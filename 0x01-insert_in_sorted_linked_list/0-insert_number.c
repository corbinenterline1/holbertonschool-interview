#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * Inserts a number into a sorted singly linked list.
  * @head: Head
  * @number: Number
  *
  * Return: Linked List with new node.
  */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *current;

	current = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = number;
	newNode->next = NULL;
	if (*head == NULL)
		*head = newNode;
	else if (current->n > number)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		while (current->next != NULL && current->next->n <= number)
			current = current->next;
		newNode->next = current->next;
		current->next = newNode;
	}
	return (newNode);
}