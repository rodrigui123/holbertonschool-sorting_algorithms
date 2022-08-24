#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

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
		if (array[j] > pivot && highest_value_index == -1) /*si encuentra alguno menor que el pivot*/
		{
			highest_value_index = j;
			i++;
		}
		if (array[j] < pivot && highest_value_index != -1)
		{
			aux = array[highest_value_index];
			array[highest_value_index] = array[j];
			array[j] = aux;
			highest_value_index = -1;
			print_array(array, size);
		}
	}
	if (highest_value_index)
	{
		aux = array[highest_value_index];
		array[i] = array[sup];
		array[sup] = aux;
		highest_value_index = -1;
		print_array(array, size);
	}
}

void quick_sort(int *array, size_t size)
{
	size_t low = 0, sup = size - 1;

	low = quick_sort_aux(array, size, 0, sup);

}
