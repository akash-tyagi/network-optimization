/*
 * Max_Capacity_Dijkstra_With_Heap.c
 *
 *  Created on: 26-Nov-2014
 *      Author: akash
 */
#include "Max_Capacity_Dijkstra_With_Heap.h"

void dijsktra(struct Graph *graph, struct Dijkstra_Arrays* results,
		int source_vertex, int target_vertex) {
	PRINT_TEXT("\n...Starting Dijkstra");

	struct Heap *heap = create();
	//		insert_heap(heap, vertex++, edge_weight);

	struct List_Node *fringe_list = NULL;
	int *dad = results->dad;
	int *dist = results->dist;
	int status[MAX_VERTICES];
	memset(status, 0, MAX_VERTICES);

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
	PRINT_TEXT("\n...Dijkstra Done");
}

void print_path(struct Dijkstra_Arrays* results, int source_vertex,
		int target_vertex) {
	PRINT_TEXT("..Printing Path..\n");
	int *dad = results->dad;
	int *dist = results->dist;
	printf("Max Capacity Path:%d -- ", results->dist[target_vertex]);
	printf("Path:\n");
	int vertex = target_vertex;
	int count = 0;
	while (vertex != -1) {
		PRINT_VALUES(vertex, dist[vertex]);
		vertex = dad[vertex];
	}
}

int main() {
	clock_t start = clock();
	double cpu_time;

	struct Dijkstra_Arrays results;
	struct Graph *graph = generate_graph_type_1();

	//printGraph(graph);
	generate_path(graph, 0, 3479);
	//printGraph(graph);

	dijsktra(graph, &results, 0, 1);
	print_path(&results, 0, 1);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return EXIT_SUCCESS;
}
