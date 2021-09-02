#include "search_algos.h"

/**
 * advanced_binary - Advanced binary search.
 * @array: Pointer to head of sorted array.
 * @size: Size of the array.
 * @value: Search value.
 * Return: First index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int high = size - 1;
	int index;
	int low = 0;

	if (value < array[0] || array == NULL)
		return (-1);
	index = recursive_binary(array, low, high, value);
	return (index);
}

/**
 * recursive_binary - Recursive binary search with the array to string.
 * @array: Pointer to head of the sorted array.
 * @low: Low end of array.
 * @high: High end of array.
 * @value: Target value.
 * Return: First index of value or -1
 */
int recursive_binary(int *array, int low, int high, int value)
{
	if (high >= low)
	{
		int i, index, mid;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
		}
		printf("\n");
		mid = low + (high - low) / 2;
		/* Base condition for advanced search. */
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		/* Discard right search space. */
		else if (array[mid] >= value)
			index = recursive_binary(array, low, mid, value);
		/* Discard left search space. */
		else
			index = recursive_binary(array, mid + 1, high, value);
		return (index);
	}
	return (-1);
}
