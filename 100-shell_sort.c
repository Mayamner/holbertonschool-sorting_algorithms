#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence
 * @array: The array to sort
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
