/*
 * Max_Capacity_Dijkstra.h
 *
 *  Created on: 26-Nov-2014
 *      Author: akash
 */
#include "Graph.c"
#include "Max-Heap.c"
#include "Linked_List.c"
#ifndef MAX_CAPACITY_DIJKSTRA_H_
#define MAX_CAPACITY_DIJKSTRA_H_

struct Dijkstra_Arrays {
	int dad[MAX_VERTICES];
	int dist[MAX_VERTICES];
};

double dijsktra(struct Graph*, struct Dijkstra_Arrays*, int, int);
void print_max_capacity_path_dijkstra(struct Dijkstra_Arrays*, int, int);
double dijsktra_with_heap(struct Graph*, struct Dijkstra_Arrays*, int, int);
void print_max_capacity_path_dijkstra_2(struct Dijkstra_Arrays* results,
		int source_vertex, int target_vertex);
#endif /* MAX_CAPACITY_DIJKSTRA_H_ */
