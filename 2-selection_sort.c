#include "sort.h"

/**
 * swap_values - Swaps two integer values.
 * @val_1: Pointer to the first integer.
 * @val_2: Pointer to the second integer.
 *
 * Description: This function swaps the values pointed to by the given
 * pointers.
 *
 * Return: Nothing.
 */

void swap_values(int *val_1, int *val_2)
{
	int temp = *val_1;
	*val_1 = *val_2;
	*val_2 = temp;
}


/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Selection sort algorithm and prints the array after each time two
 * elements are swapped.
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	unsigned int itr, index, min_val_index;

	if (array == NULL || size < 2)
		return;

	for (itr = 0; itr < size - 1; itr++)
	{
		min_val_index = itr;
		for (index = itr + 1; index < size; index++)
		{
			if (array[index] < array[min_val_index])
				min_val_index = index;
		}

		if (min_val_index != itr)
		{
			swap_values(&array[min_val_index], &array[itr]);
			print_array(array, size);
		}
	}
}
