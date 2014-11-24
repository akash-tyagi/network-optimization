#include "Max_Capacity_Dijkstra_Without_Heap.h"

void dijsktra(struct Graph *graph, int source_vertex, int target_vertex) {
	int status[MAX_VERTICES];
	int dad[MAX_VERTICES];
	int dist[MAX_VERTICES];

	memset(status, 0, MAX_INPUT);
	memset(dad, 0, MAX_VERTICES);
	memset(dist, 0, MAX_VERTICES);

	status[source_vertex] = STATUS_INTREE;
	dad[source_vertex] = -1;
	dist[source_vertex] = 0;




}
