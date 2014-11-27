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

#define GRAPH_PAIRS 1
#define VERTEX_PAIRS 1
#define TOTAL_RESULTS (GRAPH_PAIRS*2*VERTEX_PAIRS*3)
struct Network_Result {
	int graph_type;
	double time_by_kruskal;
	double time_by_dijkstra_with_heap;
	double time_by_dijkstra;
};

#endif /* NETWORK_OPTIMIZATION_H_ */
