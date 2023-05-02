#include "lists.h"

/**
 * free_listint2 - Write a function that frees a listint_t list.
 * @head: pointer to address of the head of the listint_t.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;
	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	head = NULL;
}