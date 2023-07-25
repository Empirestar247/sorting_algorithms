#include "sort.h"

/**
 * merge_sort - sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_helper(arr, array, 0, size);
	free(arr);
}

/**
 * merge_helper - recursive function that merge sorts an array
 * @arr: copy array
 * @array: array to merge sort
 * @lt: index of the left element
 * @rgt: index of the right element
 */
void merge_helper(int *arr, int *array, size_t lt, size_t rgt)
{
	size_t md;

	if (rgt - lt > 1)
	{
		md = (rgt - lt) / 2 + lt;
		merge_helper(arr, array, lt, md);
		merge_helper(arr, array, md, rgt);
		sub_merge(arr, array, lt, md, rgt);
	}
}

/**
 * sub_merge - merges subarrays
 * @arr: copy array
 * @array: array to merge
 * @lt: index of the left element
 * @md: index of the middle element
 * @rgt: index of the right element
 */
void sub_merge(int *arr, int *array, size_t lt,
		size_t md, size_t rgt)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + lt, md  - lt);
	printf("[right]: ");
	print_array(array + md, rgt - md);

	for (i = lt, j = md; i < md && j < rgt; k++)
	{
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	}

	while (i < md)
		arr[k++] = array[i++];
	while (j < rgt)
		arr[k++] = array[j++];

	for (k = lt, i = 0; k < rgt; k++)
		array[k] = arr[i++];

	printf("[Done]: ");
	print_array(array + lt, rgt - lt);
}
