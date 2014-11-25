/*
 * Max_Capacity_Dijkstra_Without_Heap.h
 *
 *  Created on: 24-Nov-2014
 *      Author: akash
 */

#include "Source_Header.h"
#include "Graph.c"
#include "Linked_List.c"
#include "Random_Vertex.c"

#ifndef MAX_CAPACITY_DIJKSTRA_WITHOUT_HEAP_H_
#define MAX_CAPACITY_DIJKSTRA_WITHOUT_HEAP_H_

#define STATUS_UNSEEN 0
#define STATUS_FRINGE 1
#define STATUS_INTREE 2

struct Dijkstra_Arrays {
	int dad[MAX_VERTICES];
	int dist[MAX_VERTICES];
};

void dijsktra(struct Graph*, struct Dijkstra_Arrays*, int, int);
void print_path(struct Dijkstra_Arrays*, int, int);
void generate_path(struct Graph*, int ,int);
#endif /* MAX_CAPACITY_DIJKSTRA_WITHOUT_HEAP_H_ */
