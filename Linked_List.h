/*
 * Linked_List.h
 *
 *  Created on: 24-Nov-2014
 *      Author: akash
 */

#include "Source_Header.h"
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
struct list_node {
	int vertex;
	int dist;
	struct list_node* next;
};

void insert_list(struct list_node**, int, int);
struct list_node* get_max_fringe(struct list_node *);
#endif /* LINKED_LIST_H_ */
