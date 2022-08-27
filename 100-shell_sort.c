#include "sort.h"

/**
 * shell_sort - Entry point
 * @array: is the array to order.
 * @size: is the size of the array.
 *
 * Return: Always 0
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 0, i = 0, j = 0;
	int aux = 0;

	if ((size < 2) || !array)
		return;
	while (n < (size / 3))
		n = (n * 3) + 1;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			aux = array[i]; /*valor a insertar*/
			j = i;
			while ((j >= n) && array[j - n] >= aux)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = aux;
		}
		print_array(array, size);
		n = (n - 1) / 3; /*nuevo intervalo*/
	}

}
