#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 *              sort algorithm and the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	/* Generate the maximum Knuth sequence gap less than size */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start sorting using the generated gap */
	while (gap > 0)
	{
		/* Perform insertion sort for the elements separated by the gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		/* Print the array after each decrease of gap */
		print_array(array, size);
		/* Reduce the gap for the next pass */
		gap = (gap - 1) / 3;
	}
}
