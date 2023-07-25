#include "deck.h"

/**
 * sort_deck - sorts a deck of card
 * @deck: doubly linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *_now;
	size_t _length;
	deck_node_t *one, *two, *three, *four;

	_length = len_list(*deck);

	if (!deck || !*deck || _length < 2)
		return;

	_now = *deck;
	while (_now)
	{
		if (_now->prev && v_card(_now) < v_card(_now->prev))
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
				*deck = three;
			two->prev = three;
			_now = *deck;
			continue;
		}
		else
			_now = _now->next;
	}
}

/**
 * v_card - returns the value of a card
 * @node: card in a deck
 *
 * Return: value between 1 and 52
 */
int v_card(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!compare_str(node->card->value, val[i - 1]))
			kind_val = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!compare_str(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}

	return (kind_val);
}

/**
 * compare_str - compares two strings
 * @str_one: first string to compare
 * @str_two: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int compare_str(const char *str_one, const char *str_two)
{
	while (*str_one == *str_two)
	{
		if (*str_one == '\0')
		{
			return (0);
		}
		str_one++;
		str_two++;
	}
	return (*str_one - *str_two);
}

/**
 * len_list - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t len_list(deck_node_t *list)
{
	size_t _length = 0;

	while (list)
	{
		_length++;
		list = list->next;
	}
	return (_length);
}
