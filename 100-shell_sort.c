#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, pip = 0;
	int mim = 0;

	if (array == NULL || size < 2)
		return;

	while (pip < size / 3)
		pip = pip * 3 + 1;

	for (; pip > 0; pip = (pip - 1) / 3)
	{
		for (i = pip; i < size; i++)
		{
			mim = array[i];
			for (; j >= pip && array[j - pip] > mim;
					j -= pip)
			{
				if (array[j] != array[j - pip])
					array[j] = array[j - pip];
			}
			if (array[j] != mim)
				array[j] = mim;

		}
		print_array(array, size);
	}
}
