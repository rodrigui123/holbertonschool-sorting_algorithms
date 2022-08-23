#include "sort.h"

/**
 * selection_sort - sorts array of integers using the Selection sort algorithm
 * @array: the list
 * @size: size of list.
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	size_t sizeaux = 0;
	int min = array[0];
	unsigned long int i = 0, j = 0;

	if (size < 2 || array[0] == '\0')
		return;
	while (sizeaux < size)
	{
		j = sizeaux;
		for (i = sizeaux; i < size; i++)
		{
			if (min > array[i] && (array[i] < array[j]))
				j = i;
		}
		if (array[j] != min)
		{
			min = array[j]; /* guardo el minimo en min */
			array[j] = array[sizeaux]; /* le doy el valor de sizeaux a J */
			array[sizeaux] = min; /* coloco el valor del min en sizeaux */
			print_array(array, size);
		}
		sizeaux++; /* achico la lista a medida que seteo valor */
		min = array[sizeaux]; /* valor de min en posc de sizeaux */
	}
}
