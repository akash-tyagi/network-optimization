/*
 * Max_Capacity_Kruskal.h
 *
 *  Created on: 26-Nov-2014
 *      Author: akash
 */

#include "Graph.c"
#include "Heap_For_Edges.c"
#include "Queue.c"
#include "Set_Operations.c"

#ifndef MAX_CAPACITY_KRUSKAL_H_
#define MAX_CAPACITY_KRUSKAL_H_

struct BFS_Result {
	int *path, max_capacity;
};

double kruskal(struct Graph *, int, int);
struct BFS_Result* breadth_first_search(struct Graph*, int, int);
void print_max_capacity_path_krukskal(struct Graph*, int, int);

#endif /* MAX_CAPACITY_KRUSKAL_H_ */
