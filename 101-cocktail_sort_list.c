#include "sort.h"

/**
 * len_list - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t len_list(listint_t *list)
{
	size_t _length = 0;

	while (list)
	{
		_length++;
		list = list->next;
	}
	return (_length);
}

/**
 * nodes_swap - function swaps nodes at pointer p with the following node
 * @h_list: head of list
 * @ptr: pointer to node
 */
void nodes_swap(listint_t **h_list, listint_t **ptr)
{
	listint_t *one, *two, *three, *four;

	one = (*ptr)->prev;
	two = *ptr;
	three = (*ptr)->next;
	four = (*ptr)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*h_list = three;
	two->prev = three;
	*ptr = three;
}

/**
 *  cocktail_sort_list - function sorts a doubly linked list using
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int _the_sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	ptr = *list;
	while (!_the_sorted)
	{
		_the_sorted = 1;
		while (ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				_the_sorted = 0;
				nodes_swap(list, &ptr);
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		if (_the_sorted)
			break;
		ptr = ptr->prev;
		while (ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				_the_sorted = 0;
				ptr = ptr->prev;
				nodes_swap(list, &ptr);
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
	}
}
