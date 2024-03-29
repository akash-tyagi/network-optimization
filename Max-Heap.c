#include "Heap.h"

#ifndef MAX_HEAP_C_
#define MAX_HEAP_C_

struct Heap* create() {
	struct Heap *heap = malloc(sizeof(struct Heap));
	if (heap == NULL) {
		printf("memory allocation failed");
		exit(1);
	}
	heap->curr_size = 0;
	heap->max_size = MAX_VERTICES;
	heap->A = malloc(sizeof(int) * heap->max_size);
	heap->D = malloc(sizeof(int) * heap->max_size);
	if (heap->A == NULL) {
		printf("memory allocation failed");
		exit(1);
	}
	return heap;
}

int is_heap_empty(struct Heap *heap) {
	if (heap->curr_size <= 0)
		return 1;
	return -1;
}

void insert_heap(struct Heap *heap, int vertex, int edge_weight) {
	if (heap->curr_size == heap->max_size) {
		printf("Heap Insertion Failed: HEAP FULL \n");
		exit(1);
	}

	heap->curr_size++;
	int index = heap->curr_size - 1;
	heap->A[index] = vertex;
	heap->D[vertex] = edge_weight;

	while (parentIndex(index) >= 0
			&& heap->D[heap->A[parentIndex(index)]] < heap->D[heap->A[index]]) {
		swap_heap_elements(heap, parentIndex(index), index);
		index = parentIndex(index);
	}
}
void update_heap(struct Heap *heap, int vertex, int new_weight) {
	int i = 0;
	while (i < heap->curr_size && heap->A[i] != vertex) {
		i++;
	}
	if (i >= heap->curr_size)
		return;

	int old_weight = heap->D[heap->A[i]];
	heap->D[heap->A[i]] = new_weight;
	if (old_weight < new_weight) {
		heapify_up(heap, i);
	} else {
		heapify_down(heap, i);
	}
}

void heapify_down(struct Heap *heap, int index) {
	if (index >= heap->curr_size)
		return;
	int left_index = leftChildIndex(index);
	int right_index = rightChildIndex(index);
	int min = index;
	if (left_index < heap->curr_size
			&& heap->D[heap->A[min]] < heap->D[heap->A[left_index]]) {
		min = left_index;
	}
	if (right_index < heap->curr_size
			&& heap->D[heap->A[min]] < heap->D[heap->A[right_index]]) {
		min = right_index;
	}
	if (min == index)
		return;
	swap_heap_elements(heap, index, min);
	heapify_down(heap, min);
}

void heapify_up(struct Heap *heap, int index) {
	while (parentIndex(index) >= 0
			&& heap->D[heap->A[parentIndex(index)]] < heap->D[heap->A[index]]) {
		swap_heap_elements(heap, parentIndex(index), index);
		index = parentIndex(index);
	}
}

void swap_heap_elements(struct Heap *heap, int index1, int index2) {
	int temp;
	temp = heap->A[index1];
	heap->A[index1] = heap->A[index2];
	heap->A[index2] = temp;
}

int get_min_max(struct Heap *heap) {
	if (heap == NULL || heap->curr_size <= 0) {
		printf("Heap Does Not Exist\n");
		return -1;
	}
	int max_vertex = heap->A[0];
	heap->A[0] = heap->A[heap->curr_size - 1];
	heap->curr_size--;
	heapify_down(heap, 0);
	return max_vertex;
}

void print_sorted_heap(struct Heap *heap) {
	int isorderd = TRUE, prev = INT_MAX;
	while (heap->curr_size > 0) {
		int index = get_min_max(heap);
		if (heap->D[index] > prev) {
			isorderd = FALSE;
		}
		prev = heap->D[index];
		printf("%d %d | ", index, heap->D[index]);
	}
	if (isorderd == FALSE) {
		PRINT_TEXT("WRONG ORDER")
	}
}

void print_heap(struct Heap *heap) {
	printf("\nHeap Structure:\n");
	int i = 0;
	while (i < heap->curr_size) {
		PRINT_VALUES(heap->A[i], heap->D[heap->A[i]]);
		i++;
	}
}

int parentIndex(int index) {
	return (index - 1) / 2;
}

int leftChildIndex(int index) {
	return 2 * index + 1;
}

int rightChildIndex(int index) {
	return 2 * index + 2;
}

//main() {
//	clock_t start = clock();
//	double cpu_time;
//	time_t t;
//	struct Heap *heap = create();
//	srand((unsigned) time(&t));
//
//	int vertex = 0, edge_weight;
//	while (vertex < MAX_VERTICES) {
//		edge_weight = rand() % MAX_WEIGHT_EDGE;
//		PRINT_VALUES(vertex, edge_weight);
//		insert_heap(heap, vertex++, edge_weight);
//	}
//
//	update_heap(heap, 2, -1);
//
//	print_sorted_heap(heap);
//
//	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
//	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
//
//}

#endif
