/*
 ============================================================================
 Name        : Network_Optimization.c
 Author      : Akash
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Network_Optimization.h"

struct Graph* generate_graph_type_1() {
	struct Graph *graph = constructGraph();
	fillAdjacencyList(graph, TYPE_1_DEGREE);
	return graph;
}

struct Graph* generate_graph_type_2() {
	struct Graph *graph = constructGraph();
	fillAdjacencyList(graph, TYPE_2_DEGREE);
	return graph;
}

int main(void) {
	clock_t start = clock();
	double cpu_time;

	struct Graph *graph = constructGraph();
	if (graph == NULL) {
		printf("Memory Allocation Failed");
		exit(1);
	}

	fillAdjacencyList(graph, 6);
	printGraph(graph);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return EXIT_SUCCESS;
}
