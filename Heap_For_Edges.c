/*
 * Edge_Heap_On_Edges.c
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Heap_For_Edges.h"

#ifndef HEAP_FOR_EDGES_C_
#define HEAP_FOR_EDGES_C_

struct Edge_Heap* create_edge_heap() {
	struct Edge_Heap *heap = malloc(sizeof(struct Edge_Heap));
	if (heap == NULL) {
		printf("memory allocation failed");
		exit(1);
	}
	heap->curr_size = 0;
	heap->max_size = MAX_VERTICES;
	heap->A = malloc(sizeof(struct Edge) * heap->max_size);
	if (heap->A == NULL) {
		printf("memory allocation failed HEAP");
		exit(EXIT_FAILURE);
	}
	return heap;
}

int is_edge_heap_empty(struct Edge_Heap *heap) {
	if (heap->curr_size <= 0)
		return 1;
	return -1;
}

void insert_edge_heap(struct Edge_Heap *heap, int vertex1, int vertex2,
		int edge_weight) {
	if (heap->curr_size == heap->max_size) {
		struct Edge *a = malloc(sizeof(struct Edge) * heap->max_size * 2);
		if (a == NULL) {
			printf("Edge_Heap Insertion Failed: HEAP FULL \n");
			exit(1);
		}
		memcpy(a, heap->A, heap->max_size * sizeof(struct Edge));
		heap->max_size = 2 * heap->max_size;
		heap->A = a;
	}

	heap->curr_size++;
	int index = heap->curr_size - 1;

	heap->A[index].vertex1 = vertex1;
	heap->A[index].vertex2 = vertex2;
	heap->A[index].weight = edge_weight;
}

void heapify_down_edge_heap(struct Edge_Heap *heap, int index) {
	if (index >= heap->curr_size)
		return;
	int left_index = left_child_index(index);
	int right_index = right_child_index(index);
	int min = index;
	if (left_index < heap->curr_size
			&& heap->A[min].weight < heap->A[left_index].weight) {
		min = left_index;
	}
	if (right_index < heap->curr_size
			&& heap->A[min].weight < heap->A[right_index].weight) {
		min = right_index;
	}
	if (min == index)
		return;
	swap_edge_heap_elements(heap, index, min);
	heapify_down_edge_heap(heap, min);
}

void swap_edge_heap_elements(struct Edge_Heap *heap, int index1, int index2) {
	int temp;

	temp = heap->A[index1].vertex1;
	heap->A[index1].vertex1 = heap->A[index2].vertex1;
	heap->A[index2].vertex1 = temp;

	temp = heap->A[index1].vertex2;
	heap->A[index1].vertex2 = heap->A[index2].vertex2;
	heap->A[index2].vertex2 = temp;

	temp = heap->A[index1].weight;
	heap->A[index1].weight = heap->A[index2].weight;
	heap->A[index2].weight = temp;

}

struct Edge* get_max(struct Edge_Heap *heap) {
	if (heap == NULL || heap->curr_size <= 0) {
		printf("Edge_Heap Does Not Exist\n");
		return NULL;
	}
	struct Edge *min_edge = malloc(sizeof(struct Edge));

	min_edge->vertex1 = heap->A[0].vertex1;
	min_edge->vertex2 = heap->A[0].vertex2;
	min_edge->weight = heap->A[0].weight;

	swap_edge_heap_elements(heap, 0, heap->curr_size - 1);
	heap->curr_size--;
	heapify_down_edge_heap(heap, 0);
	return min_edge;
}

void heapsort(struct Edge_Heap *heap) {
	int i;
	for (i = heap->curr_size / 2; i >= 0; i--) {
		heapify_down_edge_heap(heap, i);
	}
	int heap_size = heap->curr_size;
	for (i = heap->curr_size - 1; i >= 1; i--) {
		heap->curr_size--;
		swap_edge_heap_elements(heap, 0, heap->curr_size);
		heapify_down_edge_heap(heap, 0);
	}
	heap->curr_size = heap_size;
}

void print_sorted_edge_heap(struct Edge_Heap *heap) {
	while (heap->curr_size > 0) {
		struct Edge *edge = get_max(heap);
		printf("%d %d  %d\n", edge->vertex1, edge->vertex2, edge->weight);
	}
}

void print_edge_heap(struct Edge_Heap *heap) {
	printf("\nEdge_Heap Structure:\n");
	int i = 0;
	while (i < heap->curr_size) {
		PRINT_VALUES(heap->A[i].vertex1, heap->A[i].weight);
		i++;
	}
}

int parent_index(int index) {
	return (index - 1) / 2;
}

int left_child_index(int index) {
	return 2 * index + 1;
}

int right_child_index(int index) {
	return 2 * index + 2;
}

//main() {
//	clock_t start = clock();
//	double cpu_time;
//	time_t t;
//	struct Edge_Heap *heap = create_edge_heap();
//	srand((unsigned) time(&t));
//
//	int vertex = 0, edge_weight;
//	while (vertex < MAX_VERTICES) {
//		edge_weight = rand() % MAX_WEIGHT_EDGE;
//		PRINT_VALUES(vertex, edge_weight);
//		insert_edge_heap(heap, vertex++, rand() % 10, edge_weight);
//	}
//	heapsort(heap);
////	print_edge_heap(heap);
////	print_sorted_edge_heap(heap);
//
//	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
//	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
//
//}

#endif
