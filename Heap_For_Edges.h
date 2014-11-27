/*
 * Heap_On_Edges.h
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"

#ifndef HEAP_ON_EDGES_H_
#define HEAP_ON_EDGES_H_

struct Edge {
	int vertex1, vertex2, weight;
};

struct Heap {
	struct Edge *A; // store the vertices
	int curr_size;
	int max_size;
};

struct Heap* create();
int parentIndex(int index);

int leftChildIndex(int);
int rightChildIndex(int);
void insert_heap(struct Heap *heap, int, int, int);

/*get min-max depending on heap implementation*/
struct Edge* get_min_max(struct Heap *heap);

void swap_heap_elements(struct Heap *, int, int);
void print_sorted_heap(struct Heap *);
int is_heap_empty(struct Heap *);

#endif /* HEAP_ON_EDGES_H_ */
