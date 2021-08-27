#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t root);
void sift_down(int *array, int *pop, int *kid);

#endif
