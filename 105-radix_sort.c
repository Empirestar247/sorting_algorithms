#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int the_max;
	size_t i, least_dig;

	if (!array || size < 2)
		return;

	the_max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > the_max)
			the_max = array[i];

	for (least_dig = 1; the_max / least_dig > 0; least_dig *= 10)
	{
		sort_counter(array, size, least_dig);
		print_array(array, size);
	}
}

/**
 * sort_counter - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @least_dig: least significant digit
 */
void sort_counter(int *array, size_t size, size_t least_dig)
{
	int count_arr[10] = {0}, *out_arr, l, m;
	size_t k, n;

	out_arr = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_arr[(array[k] / least_dig) % 10]++;
	for (l = 1; l < 10; l++)
		count_arr[l] += count_arr[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out_arr[count_arr[(array[m] / least_dig) % 10] - 1] = array[m];
		count_arr[(array[m] / least_dig) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out_arr[n];

	free(out_arr);
}
