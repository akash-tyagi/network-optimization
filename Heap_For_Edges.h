/*
 * Heap_For_Edges.h
 *Max-Heap which stores elements of type edges
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"

#ifndef HEAP_FOR_EDGES_H_
#define HEAP_FOR_EDGES_H_

struct Edge {
	int vertex1, vertex2, weight;
};

struct Edge_Heap {
	struct Edge *A; // store the vertices
	int curr_size;
	int max_size;
};

int parent_index(int index);
int left_child_index(int index);
int right_child_index(int index);

struct Edge_Heap* create_edge_heap();
void insert_edge_heap(struct Edge_Heap *heap, int, int, int);

/*get min-max depending on heap implementation*/
struct Edge* get_max(struct Edge_Heap *heap);

void swap_edge_heap_elements(struct Edge_Heap *, int, int);
void print_sorted_edge_heap(struct Edge_Heap *);
int is_edge_heap_empty(struct Edge_Heap *);
void heapify_down_edge_heap(struct Edge_Heap *, int);
void print_edge_heap(struct Edge_Heap *);
#endif /* HEAP_FOR_EDGES_H_ */
