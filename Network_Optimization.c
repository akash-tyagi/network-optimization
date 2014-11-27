/*
 * Network_Optimization.c
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Network_Optimization.h"

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
