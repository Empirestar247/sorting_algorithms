#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
int list_len(listint_t *l);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_helper(int *array, int lt, int rgt, size_t size);
int quick_piv(int *array, int lt, int rgt, size_t size);
void shell_sort(int *array, size_t size);
void nodes_swap(listint_t **h_list, listint_t **ptr);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_helper(int *arr, int *array, size_t lt, size_t rgt);
void sub_merge(int *arr, int *array, size_t lt,
		size_t md, size_t rgt);
void heap_sort(int *array, size_t size);
void tree_heap(int *array, size_t x, size_t idx_rt, size_t size);
void radix_sort(int *array, size_t size);
void sort_counter(int *array, size_t size, size_t least_dig);
void quick_sort_hoare(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bitonic_sort(int *array, size_t size);
void bitonic_helper(int *array, int lm, int rm, int dir, size_t size);
void bitonic_sequence(int *array, int lm, int rm, int dir);

#endif
