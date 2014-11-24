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
void heapify(struct Heap *heap, int index);
int leftChildIndex(int index);
int rightChildIndex(int index);
void insert(struct Heap *heap, int vertex, int edge_weight);
int get_min_max(struct Heap *heap);
void swap(struct Heap *heap, int index1, int index2);
void print_sorted_heap(struct Heap *heap);
void print_heap(struct Heap *heap);
#endif /* HEAP_H_ */
