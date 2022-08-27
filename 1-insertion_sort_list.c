#include "sort.h"

/**
 * swap_nodes - this function swap two nodes of a doubly linked list.
 *
 * @node_1: the first node to swap.
 * @node_2: the second node to swap.
 *
 * Return: Always void.
 */
void swap_nodes(listint_t *node_1, listint_t *node_2)
{
	listint_t *aux_1 = NULL, *aux_ant_1 = NULL, *aux_desp_2 = NULL;

	if (!node_1 || !node_2)
		return;

	aux_1 = node_1;
	if (node_1->prev)
		aux_ant_1 = node_1->prev; /*prev to node 1*/
	if (node_2->next)
		aux_desp_2 = node_2->next; /*next to node 2*/

	/*node 2*/
	node_2->next = aux_1;
	node_2->prev = aux_ant_1;
	if (aux_ant_1)
		aux_ant_1->next = node_2;
	/*node 1*/
	node_1->next = aux_desp_2;
	node_1->prev = node_2;
	if (aux_desp_2)
		aux_desp_2->prev = node_1;
}

/**
 * insertion_sort_list - Write a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 *
 * @list: is the list to order.
 *
 * Return: A list in order.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux_1 = NULL, *move = NULL, *next_to_move = NULL;

	if (!list)
		return;
	aux_1 = *list, move = *list, next_to_move = *list;
	if (!move->next) /*if exists ohter node*/
		return;

	 /*puntero parcial*/
	while (move)
	{
		if (aux_1->n > move->n)
		{
			next_to_move = aux_1;
			while (aux_1->n > move->n) /*cambio si es mayor*/
			{
				swap_nodes(aux_1, move);
				if (!move->prev) /*si swapero el primero*/
					*list = move;
				print_list(*list);
				if (move->prev)
					aux_1 = move->prev;
				else
					break;
			}
			if (next_to_move->next)
				move = next_to_move->next;
			else
				return;
		}
		else /*salteo si es menor*/
		{
			if (move->next)
				move = move->next;
			else
				return;
		}
		aux_1 = move->prev;
	}
}
