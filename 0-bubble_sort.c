#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - Sorts an array of integers in an ascending
 *               order Bubble sort.
 * @array: The array to be sorted.
 * @size: The size of the arrray.
 *
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i = 0;
	int swapped;

	if (array == NULL || size < 2)
	{
		if (size == 1)
			print_array(array, size);
		return;
	}

	while (i < size - 1)
	{
		size_t j = 0;

		swapped = 0;

		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
			j++;
		}

		/* If no elements were swapped, the array is sorted */
		if (swapped == 0)
			break;
		i++;
	}
}
