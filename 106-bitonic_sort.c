#include "sort.h"

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_helper(array, 0, size - 1, 1, size);
}

/**
 * bitonic_helper - recursive function for bitonic sort
 * @array: array to sort
 * @lm: index of the left-most element
 * @rm: index of the right-most element
 * @dir: ascending or descending
 * @size: size of the array
 */
void bitonic_helper(int *array, int lm, int rm, int dir, size_t size)
{
	int step;

	if (rm - lm >= 1)
	{
		step = (rm + lm) / 2;
		printf("Merging [%d/%lu] ", rm - lm + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + lm, rm - lm + 1);
		bitonic_helper(array, lm, step, 1, size);
		bitonic_helper(array, step + 1, rm, 0, size);
		bitonic_sequence(array, lm, rm, dir);
		printf("Result [%d/%lu] ", rm - lm + 1, size);
		if (dir)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + lm, rm - lm + 1);
	}
}

/**
 * bitonic_sequence - sorts,merges a sequence in ascending or descending order
 * @array: array to sort
 * @lm: index of the left-most element
 * @rm: index of the right-most element
 * @dir: ascending or descending
 */
void bitonic_sequence(int *array, int lm, int rm, int dir)
{
	int arr_tmp, o, step = (lm + rm) / 2, md = (rm - lm + 1) / 2;

	if (rm - lm >= 1)
	{
		for (o = lm; o < lm + md; o++)
		{
			if (dir == (array[o] > array[o + md]))
			{
				arr_tmp = array[o + md];
				array[o + md] = array[o];
				array[o] = arr_tmp;
			}
		}
		bitonic_sequence(array, lm, step, dir);
		bitonic_sequence(array, step + 1, rm, dir);
	}

}
