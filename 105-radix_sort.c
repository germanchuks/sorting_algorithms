#include "sort.h"

/**
 * count_sort - Performs counting sort on an array based on a
 * significant digit.
 * @array: The array to sort.
 * @size: The size of the array.
 * @digit: The significant digit.
 *
 * Return: Nothing.
 */

void count_sort(int *array, size_t size, int digit)
{
	int *sorted_array = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t index;

	if (sorted_array == NULL)
		return;

	for (index = 0; index < size; index++)
		count[(array[index] / digit) % 10]++;

	for (index = 1; index < 10; index++)
		count[index] += count[index - 1];

	for (index = size - 1; index < size; index--)
	{
		sorted_array[count[(array[index] / digit) % 10] - 1] = array[index];
		count[(array[index] / digit) % 10]--;
	}

	for (index = 0; index < size; index++)
		array[index] = sorted_array[index];

	print_array(array, size);

	free(sorted_array);
}


/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * Radix sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm and prints the array after each time a
 * significant digit is increased.
 *
 * Return: Nothing.
 */

void radix_sort(int *array, size_t size)
{
	int max_value, digit;
	size_t index;

	if (array == NULL || size < 2)
		return;

	max_value = array[0];

	for (index = 1; index < size; index++)
	{
		if (array[index] > max_value)
			max_value = array[index];
	}

	for (digit = 1; max_value / digit > 0; digit *= 10)
		count_sort(array, size, digit);
}
