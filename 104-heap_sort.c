#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: First integer.
 * @b: Second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Implements the sift-down algorithm for a max-heap.
 * @array: The array representing the heap.
 * @size: Total size of the array (for printing).
 * @base: The current size of the heap.
 * @root: The index of the root of the subtree to sift down.
 */
void sift_down(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	while ((left = 2 * root + 1) < base)
	{
		large = left;
		right = 2 * root + 2;
		if (right < base && array[right] > array[left])
			large = right;

		if (array[large] > array[root])
		{
			swap_ints(array + root, array + large);
			print_array(array, size);
			root = large;
		}
		else
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers using Heap Sort (Sift-down).
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
