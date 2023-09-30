#include "sort.h"

/**
 * swap_me - program that swap the nodes themselves.
 * @current: ptr
 * @current_old: ptr
 * @list: doubly linked lst
 */
void swap_me(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;

	if (temp1 != NULL)
		temp1->prev = current_old;
	if (temp2 != NULL)
		temp2->next = current;
	current->prev = temp2;
	current_old->next = temp1;
	current->next = current_old;
	current_old->prev = current;
	if (*list == current_old)
		*list = current;
	print_list(*list);
}

/**
 * cocktail_sort_list - prorgram that sorts a doubly linked list of integers
 *
 * @list: doubly linked lst
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				swap_me(check->next, check, list);
			else
				check = check->next;
		}
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				swap_me(check, check->prev, list);
			else
				check = check->prev;
		}
		first = check;
	} while (first != last);
}
