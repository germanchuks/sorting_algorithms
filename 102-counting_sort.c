#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Counting sort algorithm, and prints the list after each time two
 * elements are swapped.
 *
 * Return: Nothing.
 */

void counting_sort(int *array, size_t size)
{
	int index, max_value, *sorted_array, *count_array;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	for (max_value = array[0], index = 1; index < (int)size; index++)
	{
		if (array[index] > max_value)
			max_value = array[index];
	}

	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}
	for (index = 0; index < (max_value + 1); index++)
		count_array[index] = 0;
	for (index = 0; index < (int)size; index++)
		count_array[array[index]] += 1;
	for (index = 1; index < (max_value + 1); index++)
		count_array[index] += count_array[index - 1];
	print_array(count_array, max_value + 1);

	for (index = (int)size - 1; index >= 0; index--)
	{
		sorted_array[count_array[array[index]] - 1] = array[index];
		count_array[array[index]] -= 1;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = sorted_array[index];

	free(sorted_array);
	free(count_array);
}
