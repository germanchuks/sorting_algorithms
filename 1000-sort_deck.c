#include "deck.h"

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */

char get_value(deck_node_t *card)
{
	if (strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (strcmp(card->card->value, "1") == 0)
		return (1);
	if (strcmp(card->card->value, "2") == 0)
		return (2);
	if (strcmp(card->card->value, "3") == 0)
		return (3);
	if (strcmp(card->card->value, "4") == 0)
		return (4);
	if (strcmp(card->card->value, "5") == 0)
		return (5);
	if (strcmp(card->card->value, "6") == 0)
		return (6);
	if (strcmp(card->card->value, "7") == 0)
		return (7);
	if (strcmp(card->card->value, "8") == 0)
		return (8);
	if (strcmp(card->card->value, "9") == 0)
		return (9);
	if (strcmp(card->card->value, "10") == 0)
		return (10);
	if (strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * compare_cards - Custom comparison function for qsort.
 * @card1: Pointer to the first card node.
 * @card2: Pointer to the second card node.
 *
 * Return: An integer less than, equal to, or greater than zero if the first
 * card is less than, equal to, or greater than the second card respectively.
 */

int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = (*(const deck_node_t **)card1)->card;
	const card_t *c2 = (*(const deck_node_t **)card2)->card;

	if (c1->kind != c2->kind)
		return (c1->kind - c2->kind);

	return (get_value(*(deck_node_t **)card1) -
			get_value(*(deck_node_t **)card2));
}


/**
 * sort_deck - Sorts a deck of cards.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Description: This function sorts a deck of cards in ascending order based
 * on their kind and value. It uses the quicksort algorithm provided by the C
 * library's.
 *
 * Return: Nothing.
 */

void sort_deck(deck_node_t **deck)
{
	size_t i, deck_size;
	deck_node_t *current, **deck_array;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	deck_size = 0;
	current = *deck;
	while (current != NULL)
	{
		deck_size++;
		current = current->next;
	}

	deck_array = malloc(deck_size * sizeof(deck_node_t *));
	if (deck_array == NULL)
		return;

	current = *deck;
	for (i = 0; i < deck_size; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, deck_size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < deck_size - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}

	deck_array[0]->prev = NULL;
	deck_array[deck_size - 1]->next = NULL;

	*deck = deck_array[0];

	free(deck_array);
}
