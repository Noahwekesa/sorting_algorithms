#include "sort.h"

/**
* insertion_sort_list - program that sorts a doubly linked list of integers ,
* in ascending order using the Insertion sort algorithm
* @list: the linked list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	int n;

	if (!list)
		return;
	tmp = *list;
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->next)
			{
				if (tmp->n > tmp->next->n)
				{
					n = tmp->n;
					*(int *)&tmp->n = tmp->next->n;
					*(int *)&tmp->next->n = n;
					tmp = *list;
					print_list(*list);
					break;
				}
			}
			tmp = tmp->next;
		}
	}
}

