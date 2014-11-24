#include "graph.h"

/*
 * Using Adjacency List to represent graph
 * Node : represents the edges in the graph 
 * Graph: stores the pointers to each vertex in the graph
 */
struct Node {
	int val;
	int weight;
	struct Node* next;
};

struct Graph {
	int totalVertices;
	struct Node* list;
};

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

void fillAdjacencyList(struct Graph *g) {
	printf("...Filling List...\n");
	int i, v, j;
	time_t t;
	srand((unsigned) time(&t));

	for (i = 0; i < g->totalVertices; i++) {
		int values[g->totalVertices];
		memset(values, 0, g->totalVertices * sizeof(int));
		for (j = 0; j < MAX_DEGREES; j++) {
			do {
				v = rand() % g->totalVertices;
			} while (values[v] != 0);
			values[v] = 1;
			struct Node *new = malloc(sizeof(struct Node));
			new->val = v;
			new->weight = rand() % 5000;
			new->next = g->list[i].next;
			g->list[i].next = new;
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

main() {
	//for G2 use 1000 as need to have 20% of other vertices
	clock_t start = clock();
	double cpu_time;

	struct Graph *g = constructGraph();
	if (g == NULL) {
		printf("Memory Allocation Failed");
		exit(1);
	}

	fillAdjacencyList(g);
	printGraph(g);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return 0;
}