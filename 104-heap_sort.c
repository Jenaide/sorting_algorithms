#include "sort.h"

/**
 * swap_root - A function that swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @hi: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t hi, size_t size)
{
	size_t lo = 0, mix = 0, tmp = 0;
	int mim = 0;

	while ((lo = (2 * root + 1)) <= hi)
	{
		tmp = root;
		mix = lo + 1;
		if (array[tmp] < array[lo])
			tmp = lo;
		if (mix <= hi && array[tmp] < array[mix])
			tmp = mix;
		if (tmp == root)
			return;
		mim = array[root];
		array[root] = array[tmp];
		array[tmp] = mim;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - A function that sorts an array using heap algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t hi = 0, gap = 0;
	int tmp = 0;

		if (array == NULL || size < 2)
			return;

		for (gap = (size - 2) / 2; 1; gap--)
		{
			swap_root(array, gap, size - 1, size);
			if (gap == 0)
				break;
		}

		hi = size - 1;
		while (hi > 0)
	{
		tmp = array[hi];
		array[hi] = array[0];
		array[0] = tmp;
		print_array(array, size);
		hi--;
		swap_root(array, 0, hi, size);
	}
}
