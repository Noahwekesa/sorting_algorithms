#include "sort.h"
#include <stdio.h>
/**
 * prints_results - Prints data
 * @msg: message
 * @a: array
 * @from: from
 * @to: to
 * Return: no return
 */
void prints_results(char *msg, int *a, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge_elements - program that Merge sort algorithm
 * @a: arr
 * @low: lowest index
 * @middle: middle index
 * @high: high index
 * @buff: buffer
 * Return: Null
 */
void merge_elements(int *a, int low, int middle, int high, int *buff)
{
	int lo, lm, i;

	lo = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	prints_results("left", a, low, middle);
	prints_results("right", a, middle + 1, high);

	while (lo <= middle && lm <= high)
	{
		if (a[lo] < a[lm])
			buff[i++] = a[lo++];
		else
			buff[i++] = a[lm++];
	}

	while (lo <= middle)
		buff[i++] = a[lo++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	prints_results("Done", a, low, high);
}
/**
 * sort_element -Auxiliar function for
 * Merge sort algorithm
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 * Return: no return
 */
void sort_element(int *array, int low, int high, int *buffer)
{
	int midle;

	if (low < high)
	{
		midle = (low + high - 1) / 2;
		sort_element(array, low, midle, buffer);
		sort_element(array, midle + 1, high, buffer);
		merge_elements(array, low, midle, high, buffer);
	}
}
/**
 * merge_sort - program that sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * Merge sort algorithm
 * @array: array
 * @size: size
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	sort_element(array, 0, size - 1, buffer);
	free(buffer);
}