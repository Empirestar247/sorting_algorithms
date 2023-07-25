#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array of ints to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int o, p;
	int arr_tmp;

	if (size < 2)
		return;

	for (o = 0; o < size; o++)
	{
		for (p = 0; p < size - o - 1; p++)
		{
			if (array[p] > array[p + 1])
			{
				arr_tmp = array[p];
				array[p] = array[p + 1];
				array[p + 1] = arr_tmp;
				print_array(array, size);
			}
		}
	}
}
