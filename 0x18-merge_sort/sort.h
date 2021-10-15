#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void actual_merge_sort(int *array, int *array2, size_t l, size_t r);
void merge(int *array, int *array2, size_t l, size_t m, size_t r);
void print_array(const int *array, size_t size);
#endif
