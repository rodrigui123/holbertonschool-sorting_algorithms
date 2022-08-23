#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the Bubble sort algorithm.
 * @array: the list
 * @size: size of list
 * Return: Always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, size_aux = size - 1;
	int aux = 0;

	if (size < 2) /* caso borde */
		return;
	while (size_aux) /* mientras haya algo en la lista */
	{
		for (i = 0; i <= size_aux; i++) /* recorro la lista chequeando */
		{
			j = i;
			if ((array[j] > array[j + 1]) && (j + 1) < size_aux)
			/* entra en este if, si el aux es menor a i/j */
			{
				aux = array[j];
				array[i] = array[j + 1];
				array[j + 1] = aux;
				print_array(array, size);
			}
		}
		size_aux--; /* achico la lista cada vez que el mayor queda */
	}
}
