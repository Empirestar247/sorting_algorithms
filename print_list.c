#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints the elements of a linked list
 *
 * @list: Pointer to the head of the linked list
 */
void print_list(const listint_t *list)
{
    while (list)
    {
        printf("%d", list->n);

        if (list->next)
            printf(" -> ");
        else
            printf("\n");

        list = list->next;
    }
}

