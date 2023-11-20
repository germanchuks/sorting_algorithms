#include "sort.h"

/**
 * sift_down - Performs the sift-down operation in a heap.
 * @array: The array to sort.
 * @size: The size of the array.
 * @start: The index to start the sift-down operation.
 * @end: The end index for the heap.
 */

void sift_down(int *array, size_t size, size_t start, size_t end)
{
	int temp;
	size_t current_child, max_child;

	while (2 * start + 1 <= end)
	{
		current_child = 2 * start + 1;
		max_child = start;

		if (array[max_child] < array[current_child])
			max_child = current_child;

		if (current_child + 1 <= end && array[max_child] <
		array[current_child + 1])
			max_child = current_child + 1;

		if (max_child == start)
			return;

		temp = array[start];
		array[start] = array[max_child];
		array[max_child] = temp;

		print_array(array, size);

		start = max_child;
	}
}


/**
 * heap_sort - Sorts an array of integers in ascending order using the
 * Heap sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description - This function sorts an array of integers in ascending order
 * using the Heap sort algorithm, and prints the array after each time two
 * elements are swapped.
 *
 * Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	size_t start, end;
	int temp;

	if (array == NULL || size < 2)
		return;

	start = (size - 2) / 2;
	while (start < size)
	{
		sift_down(array, size, start, size - 1);
		if (start == 0)
			break;
		start--;
	}

	end = size - 1;
	while (end > 0)
	{
		temp = array[0];
		array[0] = array[end];
		array[end] = temp;

		print_array(array, size);

		end--;

		sift_down(array, size, 0, end);
	}
}
