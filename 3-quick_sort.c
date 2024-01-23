#include "sort.h"

/**
 * split - split the array
 * @array: the array to be splited
 * @lower: the index of the first element
 * @upper: the index of the last element
 * @size: array size
 *
 * Return: the replaced array
 */
int split(int *array, int lower, int upper, size_t size)
{
	int pivot, a, b, temp;

	a = lower;
	pivot = array[upper];
	for (b = lower; b < upper; b++)
	{
		if (array[b] < pivot)
		{
			if (a != b)
			{
				temp = array[b];
				array[b] = array[a];
				array[a] = temp;
				print_array(array, size);
			}
			a++;
		}

	}
	if (array[a] != array[b])
	{
		temp = array[a];
		array[a] = array[upper];
		array[upper] = temp;
		print_array(array, size);
	}
	return (a);
}

/**
 * quicksort - sort list using quick sort
 * @array: the array to be sorted
 * @lower: the lower index
 * @upper: the upper index
 * @size: array size
 *
 * Returns: void
 */
void quicksort(int *array, int lower, int upper, size_t size)
{
	int i;

	if (upper > lower)
	{
		i = split(array, lower, upper, size);
		quicksort(array, lower, i - 1, size);
		quicksort(array, i + 1, upper, size);
	}
}

/**
 * quick_sort - quick sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}
