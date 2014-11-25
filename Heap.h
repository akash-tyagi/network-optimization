/*
 * Heap.h
 *
 *  Created on: 23-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#ifndef HEAP_H_
#define HEAP_H_

#define MAX_SIZE 5
#define MAX_WEIGHT 20

struct Heap {
	int *A;
	int *D;
	int curr_size;
	int max_size;
};

struct Heap* create();
int parentIndex(int index);

/*maintain heap property as dist has been updated for vertex*/
void heapify(struct Heap *heap, int index);

int leftChildIndex(int index);
int rightChildIndex(int index);
void insert_heap(struct Heap *heap, int vertex, int edge_weight);

/*get min-max depending on heap implementation*/
int get_min_max(struct Heap *heap);

void swap_heap_elements(struct Heap *heap, int index1, int index2);
void print_sorted_heap(struct Heap *heap);
void print_heap(struct Heap *heap);

#endif /* HEAP_H_ */
