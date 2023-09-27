#include "sort.h"
/**
 * insertion_sort_list - sort a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *j, *tmp, *c;

	if (!list || !*list || !(*list)->next)
		return;

	c = (*list)->next;
	while (c)
	{
		j = c;
		while (j->prev && j->n < j->prev->n)
		{
			tmp = j->prev;
			if (tmp->prev)
				tmp->prev->next = j;
			j->prev = tmp->prev;
			tmp->prev = j;
			tmp->next = j->next;
			if (j->next)
				j->next->prev = tmp;
			j->next = tmp;

			if (!j->prev)
				*list = j;
			print_list(*list);
		}
		c = c->next;
	}
}
