#include "sort.h"

/**
* shell_sort - function sorts an array of integers using
* the shell sort algorithm with Knuth sequence
* @array: the array of integers
* @size: size of the array
*
* Return: none
*/
void shell_sort(int *array, size_t size)
{
	size_t the_gap = 0, p, o;
	int arr_tmp;

	if (size < 2)
		return;

	while ((the_gap = the_gap * 3 + 1) < size)
		;

	the_gap = (the_gap - 1) / 3;

	for (; the_gap > 0; the_gap = (the_gap - 1) / 3)
	{
		for (o = the_gap; o < size; o++)
		{
			arr_tmp = array[o];
			for (p = o; p >= the_gap && arr_tmp <= array[p - the_gap]; p -= the_gap)
				array[p] = array[p - the_gap];
			array[p] = arr_tmp;
		}
		print_array(array, size);
	}
}
