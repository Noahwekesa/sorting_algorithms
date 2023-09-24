/**
 * lomuto_partition_scheme - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted.
 * @low: The lowest index in the partition.
 * @high: The highest index in the partition.
 * @size: Number of elements in @array.
 * Return: The pivot index.
 */
int lomuto_partition_scheme(int *array, int low, int high, size_t size)
{
    int i = low - 1;
    int temp, j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < array[high])
        {
            i++;
            if (i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] > array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 * @array: The array to be sorted.
 * @low: The lowest index in the partition.
 * @high: The highest index in the partition.
 * @size: Number of elements in @array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition_scheme(array, low, high, size);
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void quick_sort(int *array, size_t size)
{
    quick_sort_recursive(array, 0, size - 1, size);
}