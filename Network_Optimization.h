/*
 * Network_Optimization.h
 *
 *  Created on: 24-Nov-2014
 *      Author: akash
 */

#include "Source_Header.h"
#include "Graph.c"

#ifndef NETWORK_OPTIMIZATION_H_
#define NETWORK_OPTIMIZATION_H_

#define TYPE_1_DEGREE 6
#define TYPE_2_DEGREE 100
/*each vertex with degree 6*/
struct Graph* generate_graph_type_1();

/*each vertex with edges about 20% of other vertices*/
struct Graph* generate_graph_type_2();

#endif /* NETWORK_OPTIMIZATION_H_ */
