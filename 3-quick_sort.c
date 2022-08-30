#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * quick_sort_aux - sorts an array of integers using the Quick sort
 * @array: the list
 * @size: size of the list
 * @low: lower number
 * @sup: superior number
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
		if (array[j] > pivot && highest_value_index == -1)
		/*si encuentra alguno menor que el pivot*/
		{
			highest_value_index = j;
			i++;
		}
		if (array[j] < pivot && highest_value_index != -1)
		{
			aux = array[highest_value_index];
			array[highest_value_index] = array[j];
			array[j] = aux;
			j = highest_value_index;
			highest_value_index = -1;
			print_array(array, size);
		}
	}
	if (highest_value_index > -1)
	{
		aux = array[highest_value_index];
		array[highest_value_index] = array[sup];
		array[sup] = aux;
		if ((int)sup > highest_value_index + 1)
			quick_sort_aux(array, size, highest_value_index + 1, sup);
		if ((int)low < highest_value_index - 1)
			quick_sort_aux(array, size, low, highest_value_index - 1);
	print_array(array, size);
	}
	if (highest_value_index == -1 && (sup - 1) != low)
		quick_sort_aux(array, size, low, sup - 1);
	return (0);
}
/**
 * quick_sort - same as quick sort aux
 * @size: size of list
 * @array: the list
*/
void quick_sort(int *array, size_t size)
{
	size_t sup = size - 1;

	quick_sort_aux(array, size, 0, sup);

}
