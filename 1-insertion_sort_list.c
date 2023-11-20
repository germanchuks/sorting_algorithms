#include "sort.h"

/**
 * swap_node_pos - Swap two nodes in a listint_t doubly-linked list.
 * @head: Double pointer to the head of the doubly-linked list.
 * @node_1: Double pointer to the first node to swap.
 * @node_2: Pointer to the second node to swap.
 *
 * Return: Nothing
 */

void swap_node_pos(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description - This function sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm. For each element, it compares it with
 * the elements before it, swapping positions until it reaches the correct
 * place in the sorted part of the list. It prints the list after each swap.
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *prev, *temp;

	if (list == NULL || *list == NULL || current == NULL)
		return;

	for (; current != NULL; current = temp)
	{
		temp = current->next;
		prev = current->prev;
		while (prev != NULL && current->n < prev->n)
		{
			swap_node_pos(list, &prev, current);
			print_list(*list);
		}
	}
}
