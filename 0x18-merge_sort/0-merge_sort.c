#include "sort.h"

/**
 * merge_sort - Sorts array by splitting array recursively then merge.
 * @array: Input array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *array2;

	if (size < 2)
		return;
	array2 = malloc(sizeof(int) * size);
	actual_merge_sort(array, array2, 0, size - 1);
	free(array2);
}

/**
 * actual_merge_sort - Merge sort using 2 arays.
 * @array: First array.
 * @array2: Second array.
 * @l: Left.
 * @r: Right.
 */
void actual_merge_sort(int *array, int *array2, size_t l, size_t r)
{
	size_t m;

	if (l < r)
	{
		m = (l + (r - l - 1) / 2);
		actual_merge_sort(array, array2, l, m);
		actual_merge_sort(array, array2, m + 1, r);
		merge(array, array2, l, m, r);
	}
}

/**
 * merge - Merges arrays back together.
 * @array: First array.
 * @array2: Second array.
 * @l: Left.
 * @m: Mid.
 * @r: Right.
 */
void merge(int *array, int *array2, size_t l, size_t m, size_t r)
{
	size_t i, j, k;
	size_t n1 = m - l + 1;
	size_t n2 = r - m;

	if (r - l == 0)
		return;
	for (i = 0; i < n1; i++)
		array2[i] = array[l + i];
	for (j = i; j - i < n2; j++)
		array2[j] = array[m + 1 + (j - i)];
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array2, n1);
	printf("[right]: ");
	print_array(array2 + i, n2);
	j = i, i = 0, k = l;
	while (i < n1 && j - n1 < n2)
	{
		if (array2[i] <= array2[j])
		{
			array[k] = array2[i];
			i++; }
		else
		{
			array[k] = array2[j];
			j++; }
		k++;
	}
	while (i < n1)
	{
		array[k] = array2[i];
		i++, k++;
	}
	while (j - i < n2)
	{
		array[k] = array2[j];
		j++, k++;
	}
	printf("[Done]: ");
	print_array(array + l, r - l + 1);
}
