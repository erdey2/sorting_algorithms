#include "sort.h"

/**
 * selection_sort - sort an array of lists
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Returns: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, position;
	int smallest, temp;

	for (i = 1; i < size; i++)
	{
		smallest = array[i - 1];
		position = i - 1;
		for (j = i; j < size; j++)
		{
			if (smallest > array[j])
			{
				smallest = array[j];
				position = j;
			}
		}
		if (position != i - 1)
		{
			temp = array[position];
			array[position] = array[i - 1];
			array[i - 1] = temp;
			print_array(array, size);
		}
	}
}
