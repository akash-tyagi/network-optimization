/*
 * Linked_List.h
 * Used in the Dijkstra algorithm to keep the fringe vertices and edge weights
 *  Created on: 24-Nov-2014
 *      Author: akash
 */

#include "Source_Header.h"

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct List_Node {
	int vertex;
	int weight;
	struct List_Node* next;
};

/*inserts a node in the starting of the list*/
void insert_list(struct List_Node**, int, int);

/*update the weight value for a fringe vertex*/
void update_list(struct List_Node**, int, int);

/*found by traversing array linearly*/
struct List_Node* get_max_fringe(struct List_Node **);

#endif /* LINKED_LIST_H_ */
