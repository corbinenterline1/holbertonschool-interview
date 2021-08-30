#include <stdio.h>
#include "sort.h"

/**
  * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
  * @array: Input array to be sorted.
  * @size: Size of the array.
  */
void heap_sort(int *array, size_t size)
{
	int arsi, i, temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	if (size == 2)
	{
		if (array[0] >= array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
			print_array(array, size);
		}
		return;
	}
	arsi = size;
	for (i = (arsi / 2) - 1; i >= 0; i--)
		heapify(array, size, i);
	for (i = arsi - 1; i >= 0; i--)
	{
		sift_down(array, &array[0], &array[i]);
		heapify(array, i, 0);
	}
}

/**
  * heapify - Common in-place heap construction routine.
  * @array: Input array.
  * @size: Size of array.
  * @root: Root value.
  */
void heapify(int *array, size_t size, size_t root)
{
	int l = (root * 2) + 1;
	int r = (root * 2) + 2;
	int pop = root;
	int arsi = size;

	if (l < arsi && array[l] > array[pop])
		pop = l;
	if (r < arsi && array[r] > array[pop])
		pop = r;
	if (pop != (int)root)
	{
		sift_down(array, &array[root], &array[pop]);
		heapify(array, size, pop);
	}
}

/**
  * sift_down - Sifts down results, subroutine for heapify.
  * @array: Input array.
  * @pop: Parent.
  * @kid: Kid.
  */
void sift_down(int *array, int *pop, int *kid)
{
	int temp;
	size_t i;

	temp = *pop;
	*pop = *kid;
	*kid = temp;
	for (i = 0; array[i]; i++)
		continue;
	if (pop != kid)
		print_array(array, i);
}

