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
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers using the Bubble
 * sort algorithm and prints the array after each time two elements are
 * swapped.
 *
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t itr, index;

	if (!array || size < 2)
		return;

	for (itr = 0; itr < size - 1; itr++)
	{
		swapped = false;
		for (index = 0; index < size - itr - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swapped = true;
				swap_values(&array[index], &array[index + 1]);
				print_array(array, size);
			}
		}

		if (swapped == false)
		{
			print_array(array, size);
			break;
		}
	}
}
