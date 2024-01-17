#include "sort.h"
/**
 * quick_sort - quicksort algorithm
 * @array: pointer to the array
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	quick_recursion(array, 0, size - 1, size);
}
/**
 * division - divide the array
 * @array: pointer to the array
 * @low: first int
 * @high: last int
 * @size: size of the array
 * Return: Return the position of the pivot
*/
int division(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j = low - 1;
	int i, temp;

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			j++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	j++;
	temp = array[j];
	array[j] = array[high];
	array[high] = temp;
	if (array[high] != pivot)
		print_array(array, size);
	return (j);
}
/**
 * quick_recursion - runs the recursions
 * @array: pointer to the array
 * @low: first int
 * @high: last int
 * @size: size of the array
*/
void quick_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_position = division(array, low, high, size);

		quick_recursion(array, low, pivot_position - 1, size);
		quick_recursion(array, pivot_position + 1, high, size);
	}
}
