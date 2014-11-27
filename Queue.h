/*
 * Queue.h
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Source_Header.h"
#include "Network_Properties.h"
#ifndef QUEUE_H_
#define QUEUE_H_

struct Queue {
	int front, rear;
	int capacity;
	int *array;
};

struct Queue * create_queue(int);
int is_empty_queue(struct Queue*);
int is_full_queue(struct Queue*);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
void delete_queue(struct Queue*);
#endif /* QUEUE_H_ */
