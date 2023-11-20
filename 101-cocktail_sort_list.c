#include "sort.h"

/**
 * swap_nodes_forward - Swap a node in a doubly linked list with the the node
 * in front of it.
 * @list: Double pointer to the head of a doubly linked list of integers.
 * @tail: Double pointer to the tail of the doubly linked list.
 * @current: Double pointer to the current node being swapped.
 *
 * Return: Nothing.
 */

void swap_nodes_forward(listint_t **list, listint_t **tail,
						listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}


/**
 * swap_nodes_backward - Swap a node in a doubly linked list with the node
 * before it.
 * @list: A pointer to the head of a doubly linked list of integers.
 * @tail: A pointer to the tail of the doubly linked list.
 * @current: A pointer to the current node being swapped.
 *
 * Return: Nothing.
 */

void swap_nodes_backward(listint_t **list, listint_t **tail,
						 listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Cocktail shaker sort algorithm, and prints the list after each
 * time two elements are swapped.
 *
 * Return: Nothing.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *curr;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		for (curr = *list; curr != tail; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes_forward(list, &tail, &curr);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;

		for (curr = curr->prev; curr != *list; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes_backward(list, &tail, &curr);
				print_list((const listint_t *)*list);
				swapped = 1;
			}
		}
	}
}
