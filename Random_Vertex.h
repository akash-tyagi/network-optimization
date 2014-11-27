/*
 * Random_Vertex.h
 * Generated numbers uniformly from a list of numbers.
 *  Created on: 25-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"

#ifndef RANDOM_VERTEX_H_
#define RANDOM_VERTEX_H_

static int *random_array;
static int random_array_size;

void init();

/*initialize and exclude source and target vertex*/
void initialze_random_array(int, int);

/*initialize and exclude source vertex*/
void initialze_random_array2(int);

/*get random vertex*/
int get_random_vertex();

void swap_array_elements(int *, int, int);

#endif /* RANDOM_VERTEX_H_ */
