/*
 * Random_Vertex.h
 *
 *  Created on: 25-Nov-2014
 *      Author: akash
 */
#include "Graph.h"
#include "Source_Header.h"
#ifndef RANDOM_VERTEX_H_
#define RANDOM_VERTEX_H_

static int *random_array;
static int random_array_size;

/*initialize function and exclude source and target vertex*/
void initialze_random_array(int,int);

/*get random vertex*/
int get_random_vertex();

void swap_array_elements(int *,int,int);
#endif /* RANDOM_VERTEX_H_ */
