#include "Linked_List.h"
void insert_list(struct list_node** list, int vertex, int dist) {
	struct list_node *new = malloc(sizeof(struct list_node));
	new->next = NULL;
	new->dist = dist;
	new->vertex = vertex;
	if (*list) {
		new->next = *list;
	}
	*list = new;
}

struct list_node* get_max_fringe(struct list_node *list) {
	if (!list)
		return NULL;

	struct list_node *prev, *prev_max, *curr, *max;
	prev_max = NULL, max = list;

	prev = list;
	curr = list->next;
	while (curr) {
		if (curr->dist > max->dist) {
			prev_max = prev;
			max = curr;
		}
		prev = curr;
		curr = curr->next;
	}

	if (prev_max) {
		prev_max->next = max->next;
		max->next = NULL;
	} else {

	}

	return max;
}
