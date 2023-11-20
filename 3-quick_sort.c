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

void swap(int *val_1, int *val_2)
{
	int temp = *val_1;
	*val_1 = *val_2;
	*val_2 = temp;
}


/**
 * lmt_partition - Lomuto partition scheme for QuickSort.
 * @array: Array to partition.
 * @low_idx: Starting index of the partition.
 * @high_idx: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
 */

size_t lmt_partition(int *array, size_t low_idx, size_t high_idx, size_t size)
{
	size_t itr, index = low_idx;
	int pivot = array[high_idx];

	for (itr = low_idx; itr < high_idx; itr++)
	{
		if (array[itr] <= pivot)
		{
			swap(&array[index], &array[itr]);
			if (index != itr)
				print_array(array, size);
			index++;
		}
	}

	swap(&array[index], &array[high_idx]);
	if (index != high_idx)
		print_array(array, size);

	return (index);
}


/**
 * quicksort_lmt - Implements Quick Sort using Lomuto partition scheme.
 * @array: Array to sort.
 * @low_idx: Starting index of the partition.
 * @high_idx: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */

void quicksort_lmt(int *array, size_t low_idx, size_t high_idx, size_t size)
{
	size_t partition_index;

	if (low_idx < high_idx)
	{
		partition_index = lmt_partition(array, low_idx, high_idx, size);

		if (partition_index > 0)
			quicksort_lmt(array, low_idx, partition_index - 1, size);
		quicksort_lmt(array, partition_index + 1, high_idx, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Quick sort algorithm and prints the array after each time two
 * elements are swapped.
 *
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_lmt(array, 0, size - 1, size);
}
