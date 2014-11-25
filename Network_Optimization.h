/*
 * Network_Optimization.h
 *
 *  Created on: 24-Nov-2014
 *      Author: akash
 */

#include "Source_Header.h"
#include "Graph.c"
#include "Random_Vertex.c"

#ifndef NETWORK_OPTIMIZATION_H_
#define NETWORK_OPTIMIZATION_H_

#define TYPE_1_DEGREE 6
#define TYPE_2_DEGREE 100

/*each vertex with degree 6*/
struct Graph* generate_graph_type_1();

/*each vertex with edges about 20% of other vertices*/
struct Graph* generate_graph_type_2();

/*Path between a source and target while maintaining the degree limitation*/
void generate_path(struct Graph*, int, int, int);

#endif /* NETWORK_OPTIMIZATION_H_ */
