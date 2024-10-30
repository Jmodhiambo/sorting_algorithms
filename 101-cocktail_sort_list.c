#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list
 * @left: The left node to swap
 * @right: The right node to swap
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left || !right || left == right)
		return;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;  /* Update head if left is the first node */

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - Sorts doubly linked list of integers in ascending order
 * using the Cocktail Shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end;

	if (!list || !*list || !(*list)->next)
		return;
	do {
		swapped = 0;
		start = *list;
		while (start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				start = start->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		end = start;  /* Set end to the last sorted node */
		while (end->prev)
		{
			if (end->prev->n > end->n)
			{
				swap_nodes(list, end->prev, end);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				end = end->prev;
			}
		}
		start = end->next;  /* Reset start pointer for the next pass */
	} while (swapped);
}
