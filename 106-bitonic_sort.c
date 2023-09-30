#include "sort.h"
/**
 * Bitnc_meerge - peogram that sorts a bitonic sequence in ascending order
 * @array: arr
 * @size:  array size
 * @dir: direction of sorting arr (1 for ascending, 0 for descending)
 * @start: starting idx of the sequence
 **/
void Bitnc_meerge(int *array, size_t size, int dir, size_t start)
{
    size_t i, mid = size / 2;
    int temp;

    if (size < 2)
        return;

    printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
    for (i = 0; i < start + mid; i++)
    {
        if ((array[i] > array[i + mid]) == dir)
        {
            temp = array[i];
            array[i] = array[i + mid];
            array[i + mid] = temp;
            printf("%d, ", array[i]);
            printf("%d%s", array[i + mid], i + mid + 1 == start + size ? "\n" : ", ");
        }
        else
            printf("%d%s", array[i], i + 1 == start + mid ? "\n" : ", ");
    }

    Bitnc_meerge(array, mid, dir, start);
    Bitnc_meerge(array + mid, mid, dir, start + mid);
}

/**
 * bitonic_sort - progam sorts an array of integers in
 * ascending order using the bitonic sort algorithm
 * @array: arr
 * @size: arr size
 **/
void bitonic_sort(int *array, size_t size)
{
    size_t i, mid = size / 2;

    if (size < 2)
        return;

    printf("%d", array[0]);
    for (i = 1; i < size; i++)
        printf(", %d", array[i]);
    printf("\n");

    bitonic_sort(array, mid);
    bitonic_sort(array + mid, mid);
    Bitnc_meerge(array, size, 1, 0);
}
