#include "sort.h"

/**
 * quick_sort_hoare - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
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
		quick_helper(array, piv, rgt, size);
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
	int arr_tmp, the_pvt = array[rgt];
	size_t o, p;

	o = lt - 1;
	p = rgt + 1;
	while (1)
	{
		do {
			o++;
		} while (array[o] < the_pvt);
		do {
			p--;
		} while (array[p] > the_pvt);
		if (o >= p)
			return (o);
		if (o != p)
		{
			arr_tmp = array[o];
			array[o] = array[p];
			array[p] = arr_tmp;
			print_array(array, size);
		}
	}
	return (0);
}
