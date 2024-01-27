#include "sort.h"

/**
 * counting_sort - sorts an array in ascending order using a
 * counting sort algorithm
 * @array: the array to be sorted
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int i, total, max;
	int *p, *res;
	
	if (!array || size < 2)
		return;
	
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	p = calloc((max + 1), sizeof(int));
	if (!p)
		return;
	for (i = 0; i < (int)size; i++)
		p[array[i]]++;
	for (i = 0, total = 0; i < max + 1; i++)
	{
		total = p[i] + total;
		p[i] = total;
	}
	print_array(p, max + 1);
	
	res = malloc(sizeof(int) * size);
	if (!res)
		return;
	for (i = 0; i < (int)size; i++)
	{
		res[p[array[i]] - 1] = array[i];
		p[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = res[i];
	free(p);
	free(res);
}
