#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sub_arr - Merges two subarrays of integers.
 * @sub: Subarray of an array of integers to sort.
 * @buff: A buffer to store the merged subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_sub_arr(int *sub, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(sub + front, mid - front);
	printf("[right]: ");
	print_array(sub + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	for (; i < mid; i++)
		buff[k++] = sub[i];
	for (; j < back; j++)
		buff[k++] = sub[j];
	for (i = front, k = 0; i < back; i++)
		sub[i] = buff[k++];

	printf("[Done]: ");
	print_array(sub + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @sub: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *sub, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(sub, buff, front, mid);
		merge_sort_recursive(sub, buff, mid, back);
		merge_sub_arr(sub, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
