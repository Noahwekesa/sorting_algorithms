#include "sort.h"
/**
 * bubble_sort - program that Sort an array of integers,
 * in ascending order using bubble sort algorithm
 * @array: the array thats going to be sorted
 * @size: The Size of array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t element1, element2;

	if (array == NULL || size == 0)
		return;

	for (element1 = 0; element1 < size; element1++)
	{
		for (element2 = 0; element2 < size - 1; element2++)
		{
			if (array[element2] > array[element2 + 1])
			{
				tmp = array[element2];
				array[element2] = array[element2 + 1];
				array[element2 + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}