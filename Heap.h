/*
 * Heap.h
 *
 *  Created on: 23-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"
#ifndef HEAP_H_
#define HEAP_H_

struct Heap {
	int *A; // store the vertices
	int *D; // store the edge weights
	int curr_size;
	int max_size;
};

struct Heap* create();
int parentIndex(int index);

/*maintain heap property as dist has been updated for vertex*/
void heapify_down(struct Heap *, int);
void heapify_up(struct Heap *, int);
int leftChildIndex(int index);
int rightChildIndex(int index);
void insert_heap(struct Heap *heap, int vertex, int edge_weight);

/*get min-max depending on heap implementation*/
int get_min_max(struct Heap *heap);

void swap_heap_elements(struct Heap *heap, int index1, int index2);
void print_sorted_heap(struct Heap *heap);
void print_heap(struct Heap *heap);
int is_heap_empty(struct Heap *heap);
void update_heap(struct Heap *heap, int, int);
#endif /* HEAP_H_ */
