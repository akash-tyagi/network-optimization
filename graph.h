/*
 * graph.h
 *
 *  Created on: 23-Nov-2014
 *      Author: akash
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
/*included to remove the warning coming from using memset*/
#include <string.h>
/*included to measure the time taken by the functions*/
#include<time.h>
#define MAX_DEGREES  6
#define MAX_VERTICES  10
#define MAX_WEIGHT_EDGE  5000

/*
 *Initializing Graph with total vertices count
 */
struct Graph* constructGraph();

/*
 * randomly assigns certain edges to each vertex
 */
void fillAdjacencyList(struct Graph *graph);
#endif /* GRAPH_H_ */
