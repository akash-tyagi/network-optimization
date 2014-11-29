/*
 * Network_Optimization.h
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */

#include "Source_Header.h"
#include "Network_Properties.h"
#include "Max_Capacity_Dijkstra_With_Heap.c"
#include "Max_Capacity_Dijkstra_Without_Heap.c"
#include "Max_Capacity_Kruskal.c"

#ifndef NETWORK_OPTIMIZATION_H_
#define NETWORK_OPTIMIZATION_H_

#define GRAPH_TYPE_1 1
#define GRAPH_TYPE_2 2
#define GRAPH_PAIRS 1
#define VERTEX_PAIRS 1

#define TOTAL_RESULTS (GRAPH_PAIRS*2*VERTEX_PAIRS)
struct Network_Result {
	int graph_type;
	double time_by_kruskal;
	double time_by_dijkstra_with_heap;
	double time_by_dijkstra;
};

double test_dijkstra_without_heap(struct Graph *, int, int);
double test_dijkstra_with_heap(struct Graph *, int, int);
double test_kruskal(struct Graph *, int, int);
void generate_results(struct Network_Result *, int, int, struct Graph *, int,
		int);
struct Network_Result* calculate_performacnce();
#endif /* NETWORK_OPTIMIZATION_H_ */
