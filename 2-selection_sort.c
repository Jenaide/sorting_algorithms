#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int mim = 0;
	size_t i = 0, j = 0, sel = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		sel = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[sel])
				sel = j;
		}
		if (sel != i)
		{
			mim = array[i];
			array[i] = array[sel];
			array[sel] = mim;
			print_array(array, size);
		}
	}
}
