#include "sort.h"

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_helper(array, 0, (int)size - 1, size);
}

/**
 * quick_helper - helper function for Quicksort
 * @array: array to sort
 * @lt: index of the left element
 * @rgt: index of the right element
 * @size: size of the array
 */
void quick_helper(int *array, int lt, int rgt, size_t size)
{
	int piv;

	if (lt < rgt)
	{
		piv = quick_piv(array, lt, rgt, size);
		quick_helper(array, lt, piv - 1, size);
		quick_helper(array, piv + 1, rgt, size);
	}
}

/**
 * quick_piv - gives a piv index for Quicksort
 * @array: array to find the piv in
 * @lt: index of the left element
 * @rgt: index of the right element
 * @size: size of the array
 *
 * Return: the index of the piv element
 */
int quick_piv(int *array, int lt, int rgt, size_t size)
{
	int arr_tmp, o;
	int p;

	o = lt - 1;

	for (p = lt; p < rgt; p++)
	{
		if (array[p] < array[rgt])
		{
			o++;
			if (o != p)
			{
				arr_tmp = array[o];
				array[o] = array[p];
				array[p] = arr_tmp;
				print_array(array, size);
			}
		}
	}

	if (array[rgt] < array[o + 1])
	{
		arr_tmp = array[o + 1];
		array[o + 1] = array[rgt];
		array[rgt] = arr_tmp;
		print_array(array, size);
	}

	return (o + 1);
}
