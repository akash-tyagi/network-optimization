/*
 * Random_Vertex.h
 *
 *  Created on: 25-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"
#ifndef RANDOM_VERTEX_H_
#define RANDOM_VERTEX_H_

static int *random_array;
static int random_array_size;

/*initialize function and exclude source and target vertex*/
void initialze_random_array(int, int);
void initialze_random_array2(int);

/*get random vertex*/
int get_random_vertex();

void swap_array_elements(int *, int, int);
#endif /* RANDOM_VERTEX_H_ */
