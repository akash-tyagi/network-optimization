/*
 * Max_Capacity_Dijkstra_With_Heap.c
 *
 *  Created on: 26-Nov-2014
 *      Author: akash
 */
#include "Max_Capacity_Dijkstra.h"

#ifndef MAX_CAPACITY_DIJKSTRA_WITH_HEAP_C_
#define MAX_CAPACITY_DIJKSTRA_WITH_HEAP_C_

double dijsktra_with_heap(struct Graph *graph, struct Dijkstra_Arrays* results,
		int source_vertex, int target_vertex) {
	PRINT_TEXT("_________________________________________________");
	PRINT_TEXT("...Starting Dijkstra With Heap...");
	clock_t start = clock();
	double cpu_time;
	struct Heap *heap = create();
	struct List_Node *fringe_list = NULL;
	int status[MAX_VERTICES];
	memset(results->dad, 0, MAX_VERTICES * sizeof(int));
	memset(results->dist, 0, MAX_VERTICES * sizeof(int));
	memset(status, 0, MAX_VERTICES * sizeof(int));
	int *dad = results->dad;
	int *dist = results->dist;

	status[source_vertex] = STATUS_INTREE;
	dad[source_vertex] = -1;
	dist[source_vertex] = 0;

	struct Node *edges = graph->list[source_vertex].next;
	while (edges) {
		status[edges->vertex] = STATUS_FRINGE;
		dad[edges->vertex] = source_vertex;
		dist[edges->vertex] = edges->weight;
		insert_heap(heap, edges->vertex, dist[edges->vertex]);
		edges = edges->next;
	}

	int max_fringe_vertex, edge_vertex;
	while (is_heap_empty(heap) != TRUE) {
		max_fringe_vertex = get_min_max(heap);
		status[max_fringe_vertex] = STATUS_INTREE;
		edges = graph->list[max_fringe_vertex].next;

		while (edges) {
			edge_vertex = edges->vertex;
			if (status[edge_vertex] == STATUS_UNSEEN) {
				status[edge_vertex] = STATUS_FRINGE;
				dad[edge_vertex] = max_fringe_vertex;
				dist[edge_vertex] = MIN(dist[max_fringe_vertex], edges->weight);
				insert_heap(heap, edge_vertex, dist[edge_vertex]);
			} else if (status[edge_vertex] == STATUS_FRINGE
					&& dist[edge_vertex]
							< MIN(dist[max_fringe_vertex], edges->weight)) {
				dist[edge_vertex] = MIN(dist[max_fringe_vertex], edges->weight);
				dad[edge_vertex] = max_fringe_vertex;
				update_heap(heap, edge_vertex, dist[edge_vertex]);
			}
			edges = edges->next;
		}
	}
	print_max_capacity_path_dijkstra_2(results, source_vertex, target_vertex);
	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("Total Time Taken: %f\n", cpu_time);
	PRINT_TEXT("...Dijkstra With Heap Done...");
	PRINT_TEXT("_________________________________________________");
	return cpu_time;
}

void print_max_capacity_path_dijkstra_2(struct Dijkstra_Arrays* results,
		int source_vertex, int target_vertex) {
//	PRINT_TEXT("..Printing Path..");
	int *dad = results->dad;
	int *dist = results->dist;
	PRINT_TEXT_VALUE("Max Capacity Path:", results->dist[target_vertex])
//	printf("Path:\n");
	int vertex = target_vertex;
	int count = 0;
	while (vertex != -1) {
		PRINT_VALUES(vertex, dist[vertex]);
		vertex = dad[vertex];
	}
}

//int main() {
//	clock_t start = clock();
//	double cpu_time;
//
//	struct Dijkstra_Arrays results;
//	struct Graph *graph = generate_graph_type_1();
//
//	//printGraph(graph);
//	generate_path(graph, 0, 1);
//	printGraph(graph);
//
//	dijsktra_with_heap(graph, &results, 0, 1);
//
//	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
//	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
//	return EXIT_SUCCESS;
//}

#endif
