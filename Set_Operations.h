/*
 * Set_Operations.h
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"

#ifndef SET_OPERATIONS_H_
#define SET_OPERATIONS_H_

struct Set_Arrays {
	int *dad;
	int *rank;
};

struct Set_Arrays * make_set();
int find_by_rank(struct Set_Arrays *, int);
int union_by_rank(struct Set_Arrays *, int, int);

#endif /* SET_OPERATIONS_H_ */
