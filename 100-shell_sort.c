#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence and prints the
 * array after each time two elements are swapped.
 *
 * Return: Nothing.
 */

void shell_sort(int *array, size_t size)
{
	size_t outer_idx, inner_idx, interval = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer_idx = interval; outer_idx < size; outer_idx++)
		{
			temp = array[outer_idx];

			for (inner_idx = outer_idx; inner_idx >= interval &&
										array[inner_idx - interval] > temp;
				 inner_idx -= interval)
				array[inner_idx] = array[inner_idx - interval];
			array[inner_idx] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
