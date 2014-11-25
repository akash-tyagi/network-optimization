/*
 * Graph.h
 *
 *  Created on: 23-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Linked_List.h"
#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX_VERTICES  7
#define MAX_WEIGHT_EDGE  10

struct Node {
	int vertex;
	int weight;
	struct Node* next;
};

struct Graph {
	int totalVertices;
	struct Node* list;
};
/*Initializing Graph with total vertices count*/
struct Graph* constructGraph();

/*Randomly assigns certain edges to each vertex*/
void fillAdjacencyList(struct Graph *graph, int max_degrees);

/*print all the edges for each vertex*/
void printGraph(struct Graph *g);
#endif /* GRAPH_H_ */
