#include "sort.h"

/**
 * selection_sort - sorts an array following the selection sort algorithm
 * @array: array to sort
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int o, p, the_mt;

	register int arr_tmp;

	if (size < 2)
		return;

	for (o = 0; o < size; o++)
	{
		the_mt = o;
		for (p = o + 1; p < size; p++)
		{
			if (array[p] < array[the_mt])
				the_mt = p;
		}
		arr_tmp = array[o];
		array[o] = array[the_mt];
		array[the_mt] = arr_tmp;
		if (o != the_mt)
			print_array(array, size);
	}
}
