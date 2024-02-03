#include <stddef.h>
#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
        listint_t *temp;
        listint_t *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			if (prev->prev != NULL)
			{
				prev->prev->next = current;
			}
			else
				*list = current;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			prev->next = temp;
			if (temp != NULL)
				temp->prev = prev;
			print_list(*list);
			prev = current->prev;
		}
		current = temp;
	}
}
