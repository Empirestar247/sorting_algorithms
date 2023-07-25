#include "sort.h"

/**
 * list_len - returns the length of a linked list
 * @l: pointer to the list
 *
 * Return: length of list
 */
int list_len(listint_t *l)
{
	int _length = 0;

	while (l)
	{
		_length++;
		l = l->next;
	}
	return (_length);
}

/**
 * insertion_sort_list - sorts a linked list with the Insert Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *_now = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || list_len(*list) < 2)
		return;

	_now = *list;

	while (_now)
	{
		if (_now->prev && _now->n < _now->prev->n)
		{
			one = _now->prev->prev;
			two = _now->prev;
			three = _now;
			four = _now->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			_now = *list;
			print_list(*list);
			continue;
		}
		else
			_now = _now->next;
	}
}

