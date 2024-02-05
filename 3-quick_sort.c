#include <stddef.h>
#include <stdio.h>
#include "sort.h"
/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition- Choose the last element as the pivot and place
 * all the smaller elements to its left and the largest elements to its right.
 * @array: Pointer to array of enteger
 * @low: size more low
 * @high: size more high
 * Return: i
 */
size_t lomuto_partition(int *array, size_t low, size_t high)
{
	size_t i = low - 1;
	size_t j;

	int pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}
/**
 * quick_sort_recursive - Recursive function that implements quick sort
 * on an array partition.
 * @array: Pointer to array of enteger
 * @low: size more low
 * @high: size more high
 */
void quick_sort_recursive(int *array, size_t low, size_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);
		printf("Partition: ");
		print_array(array + low, high - low + 1);
		quick_sort_recursive(array, low, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}
/**
 * quick_sort - Print the original array and then call quick_sort_recursive
 * to perform quick sort.
 * @array: Pointer to array of enteger
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	printf("Initial array: ");
	print_array(array, size);
	quick_sort_recursive(array, 0, size - 1);
}
