#include "sort.h"
/**
 * selection_sort - program that Sorts an array of integers,
 *  using the selection sort algorithm.
 * @array: The array to be sorted.
 * @size: No. of elements in @array.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx, tmp;
    int swap_occurred;
    
    if (array == NULL)
    return;

for (i = 0; i < size; i++)
{
    min_idx = i;
    swap_occurred = 0;
    
    for (j = i + 1; j < size; j++)
    {
        if (array[j] < array[min_idx])
        {
            min_idx = j;
            swap_occurred = 1;
            }
            }
            if (swap_occurred)
            {
                tmp = array[min_idx];
                array[min_idx] = array[i];
                array[i] = tmp;
                print_array(array, size);
                }
                }
}
