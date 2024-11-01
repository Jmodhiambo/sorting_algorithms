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

	while (array && i < size - 1)
	{
		size_t j = 0;

		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}

		i++;
	}
}
