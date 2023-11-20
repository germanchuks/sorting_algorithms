#include "sort.h"

/**
 * merge - Merge two sub-arrays.
 * @array: The array to sort.
 * @size: The size of the array.
 * @left: The left sub-array.
 * @left_size: The size of the left sub-array.
 * @right: The right sub-array.
 * @right_size: The size of the right sub-array.
 *
 * Return: Nothing.
 */

void merge(int *array, size_t size, int *left, size_t left_size, int *right,
		   size_t right_size)
{
	size_t left_idx = 0, right_idx = 0, merged_idx = 0;
	int *merged = malloc(sizeof(int) * size);

	if (merged == NULL)
		return;

	while (left_idx < left_size && right_idx < right_size)
	{
		if (left[left_idx] <= right[right_idx])
		{
			merged[merged_idx] = left[left_idx];
			left_idx++;
		}
		else
		{
			merged[merged_idx] = right[right_idx];
			right_idx++;
		}
		merged_idx++;
	}

	while (left_idx < left_size)
	{
		merged[merged_idx] = left[left_idx];
		left_idx++;
		merged_idx++;
	}

	while (right_idx < right_size)
	{
		merged[merged_idx] = right[right_idx];
		right_idx++;
		merged_idx++;
	}

	for (left_idx = 0; left_idx < size; left_idx++)
		array[left_idx] = merged[left_idx];

	free(merged);
}


/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Merge sort algorithm. The array is divided into two sub-arrays,
 * with the left array <= the right array. The left array is sorted before the
 * right array.
 *
 * Return: Nothing.
 */

void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	if (size > 1)
	{
		mid = size / 2;
		left = array;
		right = array + mid;

		merge_sort(left, mid);
		merge_sort(right, size - mid);

		printf("Merging...\n[left]: ");
		print_array(left, mid);
		printf("[right]: ");
		print_array(right, size - mid);

		merge(array, size, left, mid, right, size - mid);

		printf("[Done]: ");
		print_array(array, size);
	}
}
