0x1B. C - Sorting algorithms & Big O

Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
At least four different sorting algorithms
What is the Big O notation, and how to evaluate the time complexity of an algorithm
How to select the best sorting algorithm for a given input
What is a stable sorting algorithm


Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called sort.h
Don’t forget to push your header file
All your header files should be include guarded
A list/array does not need to be sorted if its size is less than 2.


**Data Structure and Functions**
For this project we are given the following print_array, and print_list functions:

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

**print_list functions:**

#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}


Sorting algorithms are essential for organizing data in a specific order. Sorting involves arranging elements in a list or array in either ascending or descending order based on a defined comparison criteria. There are numerous sorting algorithms, each with its unique characteristics, advantages, and disadvantages. The efficiency of a sorting algorithm is often measured by its time complexity, which is represented using Big O notation.

**Big O Notation:**

Big O notation is used to describe the upper bound or worst-case scenario of the time complexity of an algorithm. It provides a way to analyze how the runtime of an algorithm grows with the input size (n). In Big O notation, we discard lower-order terms and constants, focusing on the dominant term that influences the growth rate of the algorithm.

For example:
- O(1) represents constant time complexity, meaning the algorithm's runtime remains the same regardless of the input size.
- O(log n) indicates logarithmic time complexity, where the runtime grows slowly as the input size increases.
- O(n) denotes linear time complexity, where the runtime grows proportionally with the input size.
- O(n log n) represents algorithms with intermediate efficiency, often found in many efficient sorting algorithms.
- O(n^2) indicates quadratic time complexity, common in inefficient sorting algorithms.
- O(2^n) and O(n!) represent highly inefficient algorithms that are usually impractical for larger inputs.

**Sorting Algorithms:**

1. **Bubble Sort (O(n^2)):** Bubble sort repeatedly compares adjacent elements and swaps them if they are in the wrong order. It iterates through the entire list until the list is sorted.

2. **Selection Sort (O(n^2)):** Selection sort divides the list into sorted and unsorted portions. It repeatedly selects the smallest (or largest) element from the unsorted portion and swaps it with the first element of the unsorted portion.

3. **Insertion Sort (O(n^2)):** Insertion sort works by maintaining a sorted subarray and inserting each element from the unsorted portion into its correct position in the sorted subarray.

4. **Merge Sort (O(n log n)):** Merge sort is a divide-and-conquer algorithm that recursively divides the list into halves, sorts them separately, and then merges the sorted halves back together.

5. **Quick Sort (O(n log n)):** Quick sort is also a divide-and-conquer algorithm. It selects a "pivot" element, partitions the list into elements less than and greater than the pivot, and recursively applies the same process to the sublists.

6. **Heap Sort (O(n log n)):** Heap sort builds a binary heap from the list and repeatedly extracts the maximum (or minimum) element to build the sorted array.

7. **Counting Sort (O(n+k)):** Counting sort is a non-comparative sorting algorithm that works best for a range of integers with small differences between values.

8. **Radix Sort (O(nk)):** Radix sort is another non-comparative sorting algorithm that sorts numbers based on individual digits, starting from the least significant digit to the most significant digit.

It is essential to choose the right sorting algorithm based on the specific requirements of the problem and the size of the input data. Efficient sorting algorithms like Merge Sort, Quick Sort, and Heap Sort are commonly preferred for large datasets due to their O(n log n) time complexity. In contrast, less efficient algorithms like Bubble Sort and Selection Sort are often used for educational purposes or with small datasets.


In general, there are numerous sorting algorithms, such as Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, and Heap Sort, each with its unique characteristics and efficiency.

Big O notation is a way to express the upper bound or worst-case time complexity of an algorithm. It helps analyze how the algorithm's runtime grows with the size of the input (n). By analyzing the number of basic operations performed in terms of n, we can determine the growth rate and efficiency of the algorithm.

To evaluate the time complexity of an algorithm, identify the major operations performed in the algorithm and express them as a function of the input size (n). Focus on the term that dominates the growth as n approaches infinity, and simplify it to its highest order term. This term represents the time complexity of the algorithm.

The best sorting algorithm for a given input depends on several factors such as the size of the data, its initial order, and memory constraints. For larger datasets, more efficient algorithms like Merge Sort, Quick Sort, or Heap Sort (O(n log n)) are preferred. For smaller datasets or nearly sorted data, Insertion Sort or Bubble Sort (O(n^2)) might be sufficient due to their simplicity.

A stable sorting algorithm is one that maintains the relative order of elements with equal keys after sorting. In other words, if two elements have the same key, a stable sorting algorithm will ensure that their original order is preserved in the sorted output. Examples of stable sorting algorithms include Merge Sort and Counting Sort. Stability is crucial when you need to sort data based on multiple criteria or preserve the order of elements that have the same sorting key.

AUTHORS
Esther Ejimofor

Emmanuel Nmaju Ndukwe
