/*
 * graph.h
 *
 *  Created on: 23-Nov-2014
 *      Author: akash
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX_DEGREES  6
#define MAX_VERTICES  10
#define MAX_WEIGHT_EDGE  5000

/*Initializing Graph with total vertices count*/
struct Graph* constructGraph();

/*Randomly assigns certain edges to each vertex*/
void fillAdjacencyList(struct Graph *graph);

/*print all the edges for each vertex*/
void printGraph(struct Graph *g);
#endif /* GRAPH_H_ */
