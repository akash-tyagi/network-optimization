#include "Max_Capacity_Dijkstra_Without_Heap.h"

void dijsktra(struct Graph *graph, struct Dijkstra_Arrays* results,
		int source_vertex, int target_vertex) {
	PRINT_TEXT("...Starting Dijkstra");
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
		insert_list(&fringe_list, edges->vertex, dist[edges->vertex]);
		edges = edges->next;
	}

	struct List_Node * max_fringe_node = NULL;
	int max_fringe_vertex, edge_vertex;
	while (fringe_list) {
		max_fringe_node = get_max_fringe(&fringe_list);
		max_fringe_vertex = max_fringe_node->vertex;
		status[max_fringe_vertex] = STATUS_INTREE;
		edges = graph->list[max_fringe_vertex].next;

		while (edges) {
			edge_vertex = edges->vertex;
			if (status[edge_vertex] == STATUS_UNSEEN) {
				status[edge_vertex] = STATUS_FRINGE;
				dad[edge_vertex] = max_fringe_vertex;
				dist[edge_vertex] = MIN(dist[max_fringe_vertex], edges->weight);
				insert_list(&fringe_list, edge_vertex, dist[edge_vertex]);
			} else if (status[edge_vertex] == STATUS_FRINGE
					&& dist[edge_vertex]
							< MIN(dist[max_fringe_vertex], edges->weight)) {
				dist[edge_vertex] = MIN(dist[max_fringe_vertex], edges->weight);
				dad[edge_vertex] = max_fringe_vertex;
				update_list(&fringe_list, edge_vertex, dist[edge_vertex]);
			}
			edges = edges->next;
		}
	}
}

void print_path(struct Dijkstra_Arrays* results, int source_vertex,
		int target_vertex) {
	PRINT_TEXT("..Printing Path..\n");
	int *dad = results->dad;
	int *dist = results->dist;
	printf("Max Capacity Path:%d\n", results->dist[target_vertex]);
	printf("Path:\n");
	int vertex = target_vertex;
	while (vertex != -1) {
		PRINT(vertex, dist[vertex]);
		vertex = dad[vertex];
	}
}

int main() {
	clock_t start = clock();
	double cpu_time;

	struct Dijkstra_Arrays results;
	struct Graph *graph = constructGraph();
	fillAdjacencyList(graph, 6);
	printGraph(graph);

	dijsktra(graph, &results, 0, 6);
	//print_path(&results, 0, 6);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return EXIT_SUCCESS;
}
