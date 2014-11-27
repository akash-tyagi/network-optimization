/*
 * Queue.c
 *
 *  Created on: 27-Nov-2014
 *      Author: akash
 */
#include "Queue.h"

struct Queue * create_queue(int capacity) {
	struct Queue *queue = malloc(sizeof(struct Queue));
	if (!queue) {
		PRINT_TEXT("ERROR CREATING QUEUE!");
		exit(EXIT_FAILURE);
	}
	queue->capacity = capacity;
	queue->front = queue->rear = -1;
	queue->array = malloc(sizeof(int) * capacity);
	if (!queue->array) {
		PRINT_TEXT("ERROR CREATING QUEUE!");
		exit(EXIT_FAILURE);
	}
	return queue;
}

int is_empty_queue(struct Queue* queue) {
	return queue->front == -1;
}

int is_full_queue(struct Queue* queue) {
	return (queue->rear + 1) % queue->capacity == queue->front;
}

void enqueue(struct Queue* queue, int data) {
	if (is_full_queue(queue)) {
		PRINT_TEXT("QUEUE FULL");
		exit(EXIT_FAILURE);
	}
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = data;
	if (queue->front == -1)
		queue->front = queue->rear;
}

int dequeue(struct Queue* queue) {
	int data = -1;
	if (is_empty_queue(queue)) {
		PRINT_TEXT("QUEUE EMPTY");
		exit(EXIT_FAILURE);
	}
	data = queue->array[queue->front];
	if (queue->front == queue->rear) {
		queue->front = queue->rear = -1;
	} else
		queue->front = (queue->front + 1) % queue->capacity;
	return data;
}

void delete_queue(struct Queue* queue) {
	if (queue) {
		if (queue->array)
			free(queue->array);
		free(queue);
	}
}
