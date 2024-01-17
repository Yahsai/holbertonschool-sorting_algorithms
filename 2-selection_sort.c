#include "sort.h"
/**
 * selection_sort - use the selection sort method
 * @array: pointer to the array
 * @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
