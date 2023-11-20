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
 * recursive_quick_sort - Recursively sorts an array using the Quick
 * sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the partition to be sorted.
 * @right: The ending index of the partition to be sorted.
 *
 * Return: Nothing.
 */

void recursive_quick_sort(int *array, size_t size, int left, int right)
{
	int high, low, element;

	if (left < right)
	{
		element = array[right];
		high = left - 1;
		low = right + 1;

		while (1)
		{
			while (array[++high] < element)
				;

			while (array[--low] > element)
				;

			if (high < low)
			{
				swap_values(array + high, array + low);
				print_array(array, size);
			}
			else
				break;
		}

		recursive_quick_sort(array, size, left, high - 1);
		recursive_quick_sort(array, size, high, right);
	}
}


/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition scheme) and prints the
 * array after each complete iteration.
 *
 * Return: Nothing.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, size, 0, size - 1);
}
