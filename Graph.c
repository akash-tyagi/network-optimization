#include "Graph.h"

/*
 * Using Adjacency List to represent graph
 * Node : represents the edges in the graph 
 * Graph: stores the pointers to each vertex in the graph
 */

struct Graph* constructGraph() {
	printf("...Constructing Graph...\n");
	struct Graph *g = malloc(sizeof(struct Graph));
	if (g == NULL)
		return NULL;
	g->totalVertices = MAX_VERTICES;
	g->list = malloc(sizeof(struct Node) * g->totalVertices);

	int i = 0;
	while (i < g->totalVertices) {
		g->list[i].val = i;
		g->list[i].weight = INT_MAX; //Todo: check what to keep
		g->list[i].next = NULL;
		i++;
	}

	if (g->list == NULL)
		return NULL;
	printf("...Graph Construction Done...\n");
	return g;
}

void fillAdjacencyList(struct Graph *graph, int max_degrees) {
	printf("...Filling List...\n");
	int i, v, j;
	time_t t;
	srand((unsigned) time(&t));

	for (i = 0; i < graph->totalVertices; i++) {
		int values[graph->totalVertices];
		memset(values, 0, graph->totalVertices * sizeof(int));
		for (j = 0; j < max_degrees; j++) {
			do {
				v = rand() % graph->totalVertices;
			} while (values[v] != 0);
			values[v] = 1;
			struct Node *new = malloc(sizeof(struct Node));
			new->val = v;
			new->weight = rand() % 5000;
			new->next = graph->list[i].next;
			graph->list[i].next = new;
		}
	}
	printf("...Graph Filling Complete\n");
}

void printGraph(struct Graph *g) {
	int i;
	struct Node *node;
	for (i = 0; i < g->totalVertices; i++) {
		printf("\nFor Vertex:%d Adjacent Nodes Are: ", i);
		node = g->list[i].next;
		while (node) {
			printf("(%d,%d) ", node->val, node->weight);
			node = node->next;
		}
	}
}
