#include "sort.h"

/**
 * shell_sort - sort an array of integers in ascending order using the
 * shell sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t diff = 1, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	while (diff < size / 3)
		diff = diff * 3 + 1;

	while (diff > 0)
	{
		for (i = diff; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= diff && array[j - diff] > tmp)
			{
				array[j] = array[j - diff];
				j -= diff;
			}
			array[j] = tmp;
		}
		diff = (diff - 1) / 3;
		print_array(array, size);
	}
}
