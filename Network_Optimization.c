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
			} while (vertex1 != vertex2);
			generate_path(graph1, vertex1, vertex2);
			generate_path(graph2, vertex1, vertex2);

			results[count].graph_type = 1;
			results[count].time_by_dijkstra = test_dijkstra_without_heap(graph1,
					vertex1, vertex2);
			results[count].time_by_dijkstra_with_heap = test_dijkstra_with_heap(
					graph1, vertex1, vertex2);
			results[count].time_by_kruskal = test_kruskal(graph1, vertex1,
					vertex2);
			count++;

			results[count].graph_type = 2;
			results[count].time_by_dijkstra = test_dijkstra_without_heap(graph2,
					vertex1, vertex2);
			results[count].time_by_dijkstra_with_heap = test_dijkstra_with_heap(
					graph2, vertex1, vertex2);
			results[count].time_by_kruskal = test_kruskal(graph2, vertex1,
					vertex2);
			count++;
		}
	}
	return results;
}

int main() {
	struct Network_Result *results = calculate_performacnce();
	FILE* file = fopen("results.txt", "w");
	int i = 0;
	while (i < TOTAL_RESULTS) {
		fprintf(file, "%d,%f,%f,%f\n", results[i].graph_type,
				results[i].time_by_dijkstra,
				results[i].time_by_dijkstra_with_heap,
				results[i].time_by_kruskal);
		i++;
	}
	fclose(file);
	return EXIT_SUCCESS;
}
