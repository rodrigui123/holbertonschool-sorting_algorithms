#include "sort.h"
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

size_t quick_sort_aux(int *array, size_t size, size_t low, size_t sup)
{
	size_t i = -1, j = 0;
	int pivot = 0, aux = 0;
	int highest_value_index = -1;

	if (!array || size < 2)
		return (0);
	pivot = array[sup];
	for (j = low; j < sup; j++)
	{
		if (array[j] > pivot) /*si encuentra alguno menor que el pivot*/
		{
			i++;
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}
	}
}

void quick_sort(int *array, size_t size)
{
	size_t low = 0, sup = size - 1;

	low = quick_sort_aux(array, size, 0, sup);

}
