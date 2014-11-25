#include "Linked_List.h"
void insert_list(struct List_Node** list, int vertex, int dist) {
	struct List_Node *new = malloc(sizeof(struct List_Node));
	new->next = NULL;
	new->dist = dist;
	new->vertex = vertex;
	if (*list) {
		new->next = *list;
	}
	*list = new;
}

struct List_Node* get_max_fringe(struct List_Node **list) {
	if (!list || !*list)
		return NULL;

	struct List_Node *prev, *prev_max, *curr, *max;
	prev_max = NULL, max = *list;

	prev = *list;
	curr = (*list)->next;
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
	} else {
		*list = max->next;
	}
	max->next = NULL;

	return max;
}

void update_list(struct List_Node** list, int vertex, int dist) {
	struct List_Node * curr = *list;
	if (!curr)
		return;

	while (curr && curr->vertex != vertex)
		curr = curr->next;

	if (curr && curr->vertex == vertex)
		curr->dist = dist;
}

//main() {
//	clock_t start = clock();
//	double cpu_time;
//	time_t t;
//	srand((unsigned) time(&t));
//
//	struct List_Node *list = NULL;
//	int i = 0;
//	while (i++ < 100) {
//		insert_list(&list, i, rand() % 10);
//	}
//	printf("INSERTION");
//	while (list) {
//		struct List_Node * temp = get_max_fringe(&list);
//		PRINT(temp->vertex, temp->dist);
//	}
//
//	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
//	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
//	return EXIT_SUCCESS;
//}
