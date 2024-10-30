#include "sort.h"

void quicksort_helper(int *array, size_t low, size_t high, size_t size);
int partition(int *array, size_t low, size_t high, size_t size);

/**
 * quick_sort - Sorts an array of integers using Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_helper(array, 0, size - 1, size);
}

/**
 * quicksort_helper - Recursively sorts the partitions of the array.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array (needed for print).
 */
void quicksort_helper(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		/* Partition the array and get the pivot index */
		pivot_index = partition(array, low, high, size);

		/* Recursively sort elements before and after partition */
		if (pivot_index > 0) /* Ensure we don’t wrap around with size_t */
			quicksort_helper(array, low, pivot_index - 1, size);
		quicksort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - Partitions array around a pivot using Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array (needed for print).
 *
 * Return: The final index of the pivot.
 */
int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j = low;
	int temp;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (j != i)
			{
				/* Swap elements and set flag */
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			j++;
		}
	}

	/* Final swap to place pivot in correct position */
	if (j != high)
	{
		temp = array[j];
		array[j] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (j);
}
