/*
 * Max_Capacity_Dijkstra.h
 *
 *  Created on: 26-Nov-2014
 *      Author: akash
 */
#include "Graph.c"
#include "Max-Heap.c"
#ifndef MAX_CAPACITY_DIJKSTRA_WITH_HEAP_H_
#define MAX_CAPACITY_DIJKSTRA_WITH_HEAP_H_

struct Dijkstra_Arrays {
	int dad[MAX_VERTICES];
	int dist[MAX_VERTICES];
};

void dijsktra(struct Graph*, struct Dijkstra_Arrays*, int, int);
void print_path(struct Dijkstra_Arrays*, int, int);

#endif /* MAX_CAPACITY_DIJKSTRA_WITH_HEAP_H_ */
