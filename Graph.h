/*
 * Graph.h
 *
 *  Created on: 23-Nov-2014
 *      Author: akash
 */
#include "Random_Vertex.c"
#ifndef GRAPH_H_
#define GRAPH_H_


struct Node {
	int vertex;
	int weight;
	struct Node* next;
};

struct Graph {
	int totalVertices;
	struct Node* list;
};

/*each vertex with degree 6*/
struct Graph* generate_graph_type_1();

/*each vertex with edges about 20% of other vertices*/
struct Graph* generate_graph_type_2();

/*Initializing Graph with total vertices count*/
struct Graph* constructGraph();

/*Randomly assigns certain edges to each vertex*/
void fillAdjacencyList(struct Graph *graph, int max_degrees);

/*print all the edges for each vertex*/
void printGraph(struct Graph *g);

/*Path between a source and target, not maintaining the degree limitation*/
void generate_path(struct Graph*, int, int);

/*Create a link between source vertex and target vertex, not maintaining the degree*/
void link_creation(struct Graph*, int, int);
#endif /* GRAPH_H_ */
