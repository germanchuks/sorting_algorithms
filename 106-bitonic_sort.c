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
 * bitonic_sort_seq - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq_size: The size of the sequence to sort.
 * @sort_dir: The direction to sort in (0 for UP, 1 for DOWN).
 */

void bitonic_sort_seq(int *array, size_t size, size_t start, size_t seq_size,
					  int sort_dir)
{
	size_t index, step_size = seq_size / 2;

	if (seq_size > 1)
	{
		for (index = start; index < start + step_size; index++)
		{
			if ((sort_dir == 0 && array[index] > array[index + step_size]) ||
				(sort_dir == 1 && array[index] < array[index + step_size]))
				swap_values(array + index, array + index + step_size);
		}
		bitonic_sort_seq(array, size, start, step_size, sort_dir);
		bitonic_sort_seq(array, size, start + step_size, step_size, sort_dir);
	}
}


/**
 * build_bitonic - Transform an array of bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @block_size: The size of a block of the building bitonic sequence.
 * @sort_dir: The direction to sort the bitonic sequence block
 * (0 for UP, 1 for DOWN).
 *
 * Return: Nothing.
 */

void build_bitonic(int *array, size_t size, size_t start, size_t block_size,
				   int sort_dir)
{
	size_t cut = block_size / 2;
	const char *sort_desc = (sort_dir == 0) ? "UP" : "DOWN";

	if (block_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", (unsigned long)block_size,
			   (unsigned long)size, sort_desc);
		print_array(array + start, block_size);

		build_bitonic(array, size, start, cut, 0);
		build_bitonic(array, size, start + cut, cut, 1);
		bitonic_sort_seq(array, size, start, block_size, sort_dir);

		printf("Result [%lu/%lu] (%s):\n", (unsigned long)block_size,
			   (unsigned long)size, sort_desc);
		print_array(array + start, block_size);
	}
}


/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function Sort an array of integers in ascending order
 * using the Bitonic sort algorithm, and prints the array after each swap.
 *
 * Return: Nothing.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_bitonic(array, size, 0, size, 0);
}
