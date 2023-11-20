# C - Sorting algorithms & Big O

## Description
This project involves implementing and understanding various sorting algorithms, as well as the Big O notation concept for evaluating time complexity.

### File Usage
File Name | Description
--- | ---
[sort.h](https://github.com/germanchuks/monty/blob/master/sort.h) | Header file for various sorting algorithms, including bubble sort, insertion sort, selection sort, quicksort, shellsort, cocktail shaker sort, counting sort, merge sort, heapsort, radix sort, bitonic sort, and quicksort with Hoare partition. Also defines structures for a doubly linked list and prototypes for functions to print arrays and linked lists.
[0-bubble_sort.c](https://github.com/germanchuks/sorting_algorithms/blob/master/0-bubble_sort.c) | Contains the implementation of the Bubble sort algorithm for sorting an array of integers in ascending order.
[1-insertion_sort_list.c](https://github.com/germanchuks/monty/blob/master/1-insertion_sort_list.c) | Implements the Insertion sort algorithm for sorting a doubly linked list of integers in ascending order. 
[2-selection_sort.c](https://github.com/germanchuks/monty/blob/master/2-selection_sort.c) | Implements the Selection sort algorithm for sorting an array of integers in ascending order. 
[3-quick_sort.c](https://github.com/germanchuks/monty/blob/master/3-quick_sort.c) | Implements the QuickSort algorithm by utilizing the Lomuto partition scheme to sort an array of integers in ascending order.
[100-shell_sort.c](https://github.com/germanchuks/monty/blob/master/100-shell_sort.c) | Implements the Shell sort algorithm with the Knuth sequence to sort an array of integers in ascending order.
[101-cocktail_sort_list.c](https://github.com/germanchuks/monty/blob/master/101-cocktail_sort_list.c) | Implements the Cocktail shaker sort algorithm to sort a doubly linked list of integers in ascending order.
[102-counting_sort.c](https://github.com/germanchuks/monty/blob/master/102-counting_sort.c) | Contains the implementation of the Counting sort algorithm for sorting an array of integers in ascending order.
[103-merge_sort.c](https://github.com/germanchuks/monty/blob/master/103-merge_sort.c) | Contains the implementation of the Merge sort algorithm for sorting an array of integers in ascending order.
[104-heap_sort.c](https://github.com/germanchuks/monty/blob/master/104-heap_sort.c) | Contains the implementation of the Heap sort algorithm for sorting an array of integers in ascending order.
[105-radix_sort.c](https://github.com/germanchuks/monty/blob/master/105-radix_sort.c) | Contains the implementation of the LSD Radix sort algorithm for sorting an array of integers in ascending order.
[106-bitonic_sort.c](https://github.com/germanchuks/monty/blob/master/106-bitonic_sort.c) | Implements the Bitonic sort algorithm to sort an array of integers in ascending order.
[107-quick_sort_hoare.c](https://github.com/germanchuks/monty/blob/master/107-quick_sort_hoare.c) | Implements the Quick sort algorithm with the Hoare partition scheme for sorting an array of integers in ascending order.
[1000-sort_deck.c](https://github.com/germanchuks/monty/blob/master/1000-sort_deck.c) | Util;izes the quicksort algorithm provided by the C library to sort a deck of cards in ascending order based on their kind and value.
[deck.h](https://github.com/germanchuks/monty/blob/master/deck.h) | Header file that defines a deck of cards using structs and enums, represented as a doubly-linked list, and declares functions to print and sort the deck.
[0-O](https://github.com/germanchuks/monty/blob/master/0-O) | The big O notations of the time complexity of the Bubble sort algorithm.
[1-O](https://github.com/germanchuks/monty/blob/master/1-O) | The big O notations of the time complexity of the Insertion sort algorithm.
[2-O](https://github.com/germanchuks/monty/blob/master/2-O) | The big O notations of the time complexity of the Selection sort algorithm.
[3-O](https://github.com/germanchuks/monty/blob/master/3-O) | The big O notations of the time complexity of the Quick sort algorithm.
[101-O](https://github.com/germanchuks/monty/blob/master/101-O) | The big O notations of the time complexity of the Cocktail shaker sort algorithm.
[102-O](https://github.com/germanchuks/monty/blob/master/102-O) | The big O notations of the time complexity of the Counting sort algorithm.
[103-O](https://github.com/germanchuks/monty/blob/master/102-O) | The big O notations of the time complexity of the Merge sort algorithm.
[104-O](https://github.com/germanchuks/monty/blob/master/102-O) | The big O notations of the time complexity of the Heap sort algorithm.
[105-O](https://github.com/germanchuks/monty/blob/master/105-O) | The big O notations of the time complexity of the Counting sort algorithm.
[106-O](https://github.com/germanchuks/monty/blob/master/106-O) | The big O notations of the time complexity of the Bitonic sort algorithm.
[107-O](https://github.com/germanchuks/monty/blob/master/107-O) | The big O notations of the time complexity of the Quick sort algorithm.


### Compilation
```
$ gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 sort_func.c main_file.c print_array.c -o sort_exec
```

### Usage
```
./sort_exec
```

### Bugs
No known bugs.

## Authors
* **Michael Chukwunwe** (https://github.com/stuckwithprogression)
* **German Daniel** (https://github.com/germanchuks)
