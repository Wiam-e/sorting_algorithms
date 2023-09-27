#include "sort.h"

/**
 * selection_sort - sorting an array using selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int small, tmp;
	size_t i, j;

	if (!array || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		small = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[small])
				small = j;
			j++;
		}
		if (small != (int)i)
		{
			tmp = array[i];
			array[i] = array[small];
			array[small] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
