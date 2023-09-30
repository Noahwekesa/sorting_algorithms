#include "sort.h"


/**
 * radix_sort - program thatsorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int *count, *output, max, exp;
    size_t i;

    if (!array || size < 2)
        return;

    count = malloc(sizeof(int) * 10);
    output = malloc(sizeof(int) * size);
    if (!count || !output)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < size; i++)
            count[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = size - 1; (int)i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (i = 0; i < size; i++)
            array[i] = output[i];

        /* Print array after each significant digit */
        for (i = 0; i < size; i++)
        {
            printf("%d", array[i]);
            if (i != size - 1)
                printf(", ");
        }
        printf("\n");
    }

    free(count);
    free(output);
}
