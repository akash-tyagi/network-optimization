/*
 * Max_Capacity_Dijkstra_With_Heap.h
 *
 *  Created on: 26-Nov-2014
 *      Author: akash
 */
#include "Graph.c"
#include "Max-Heap.c"
#ifndef MAX_CAPACITY_DIJKSTRA_WITH_HEAP_H_
#define MAX_CAPACITY_DIJKSTRA_WITH_HEAP_H_
#define STATUS_UNSEEN 0
#define STATUS_FRINGE 1
#define STATUS_INTREE 2

struct Dijkstra_Arrays {
	int dad[MAX_VERTICES];
	int dist[MAX_VERTICES];
};

void dijsktra(struct Graph*, struct Dijkstra_Arrays*, int, int);
void print_path(struct Dijkstra_Arrays*, int, int);

#endif /* MAX_CAPACITY_DIJKSTRA_WITH_HEAP_H_ */
