#include "sort.h"

/**
 * heap_sort - sorts an array following the Heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int arr_tmp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		tree_heap(array, size, (size_t)i, size);

	for (i = size - 1; i >= 0; i--)
	{
		arr_tmp = array[i];
		array[i] = array[0];
		array[0] = arr_tmp;
		if (i != 0)
			print_array(array, size);
		tree_heap(array, (size_t)i, 0, size);
	}
}

/**
 * tree_heap - turns an array in a heap tree
 * @array: array to turn into heap
 * @x: size of the subtree
 * @idx_rt: index of the subtree in the heap
 * @size: size of the whole array
 */
void tree_heap(int *array, size_t x, size_t idx_rt, size_t size)
{
	size_t the_max, lt, rgt;
	int arr_tmp;

	the_max = idx_rt;
	lt = (idx_rt * 2) + 1;
	rgt = (idx_rt * 2) + 2;

	if (lt < x && array[lt] > array[the_max])
		the_max = lt;

	if (rgt < x && array[rgt] > array[the_max])
		the_max = rgt;

	if (the_max != idx_rt)
	{
		arr_tmp = array[idx_rt];
		array[idx_rt] = array[the_max];
		array[the_max] = arr_tmp;
		print_array(array, size);
		tree_heap(array, x, the_max, size);
	}
}
