/*
 * Network_Optimization.c
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Network_Optimization.h"
double test_dijkstra_without_heap(struct Graph *graph, int v1, int v2) {
	struct Dijkstra_Arrays results;
	return dijsktra(graph, &results, v1, v2);
}

double test_dijkstra_with_heap(struct Graph *graph, int v1, int v2) {
	struct Dijkstra_Arrays results;
	return dijsktra_with_heap(graph, &results, v1, v2);
}

double test_kruskal(struct Graph *graph, int v1, int v2) {
	return kruskal(graph, v1, v2);
}

struct Network_Result* calculate_performacnce() {
	struct Graph *graph1, *graph2;
	int total_graph_pairs = 0, total_vertex_pairs = 0, vertex1, vertex2, count =
			0;
	struct Network_Result *results = malloc(
			sizeof(struct Network_Result) * TOTAL_RESULTS);
	if (results == NULL) {
		PRINT_TEXT("MEM ALLOCATION FAILED");
		exit(EXIT_FAILURE);
	}

	while (total_graph_pairs++ < GRAPH_PAIRS) {
		graph1 = generate_graph_type_1();
		graph2 = generate_graph_type_2();

		total_vertex_pairs = 0;
		while (total_vertex_pairs < VERTEX_PAIRS) {
			vertex1 = rand() % MAX_VERTICES;
			do {
				vertex2 = rand() % MAX_VERTICES;
			} while (vertex1 == vertex2);
			generate_path(graph1, vertex1, vertex2);
			generate_path(graph2, vertex1, vertex2);
			generate_results(results, count++, GRAPH_TYPE_1, graph1, vertex1,
					vertex2);
			generate_results(results, count++, GRAPH_TYPE_2, graph2, vertex1,
					vertex2);
			total_vertex_pairs++;
		}
	}
	return results;
}

void generate_results(struct Network_Result *results, int index, int graph_type,
		struct Graph *graph, int source_vertex, int target_vertex) {
	results[index].graph_type = graph_type;
	results[index].time_by_dijkstra = test_dijkstra_without_heap(graph,
			source_vertex, target_vertex);
	results[index].time_by_dijkstra_with_heap = test_dijkstra_with_heap(graph,
			source_vertex, target_vertex);
	results[index].time_by_kruskal = test_kruskal(graph, source_vertex,
			target_vertex);
}

int main() {
	struct Network_Result *results = calculate_performacnce();
	FILE* file = fopen("results.txt", "w");
	int i = 0;
	fprintf(file, "Graph type\tDijkstra\tDijkstra-with-heap\t\tkruskal\n");
	while (i < TOTAL_RESULTS) {
		fprintf(file, "%d\t\t\t%f\t\t\t%f\t\t%f\n", results[i].graph_type,
				results[i].time_by_dijkstra,
				results[i].time_by_dijkstra_with_heap,
				results[i].time_by_kruskal);
		i++;
	}
	fclose(file);
	return EXIT_SUCCESS;
}
