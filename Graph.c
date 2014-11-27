#include "Graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Network_Properties.h"
#include "Random_Vertex.h"
#include "Source_Header.h"

/*
 * Using Adjacency List to represent graph
 * Node : represents the edges in the graph 
 * Graph: stores the pointers to each vertex in the graph
 */
struct Graph* generate_graph_type_1() {
	struct Graph *graph = constructGraph();
	fillAdjacencyList(graph, TYPE_1_DEGREE);
	return graph;
}

struct Graph* generate_graph_type_2() {
	struct Graph *graph = constructGraph();
	fillAdjacencyList(graph, TYPE_2_DEGREE);
	return graph;
}

struct Graph* constructGraph() {
	printf("...Constructing Graph...\n");
	struct Graph *g = malloc(sizeof(struct Graph));
	if (g == NULL)
		return NULL;
	g->totalVertices = MAX_VERTICES;
	g->list = malloc(sizeof(struct Node) * g->totalVertices);

	int i = 0;
	while (i < g->totalVertices) {
		g->list[i].vertex = i;
		g->list[i].weight = 0; //count of degrees
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
	int i, random_vertex, j;
	time_t t;
	srand((unsigned) time(&t));
	int **edges = (int **) malloc(MAX_VERTICES * sizeof(int *));
	if (edges == NULL) {
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < MAX_VERTICES; i++) {
		edges[i] = malloc(MAX_VERTICES * sizeof(int));
		if (edges[i] == NULL) {
			fprintf(stderr, "out of memory\n");
			exit(EXIT_FAILURE);
		}
	}

	int hack = 0;
	for (i = 0; i < graph->totalVertices; i++) {
		PRINT_TEXT_VALUE("\nVERTEX:", i);
		hack = 0;
		initialze_random_array2(i);
		while (graph->list[i].weight < max_degrees) {
			if (hack == 0) {
				do {
					random_vertex = get_random_vertex();
					if (random_vertex == -1) {
						hack = 1;
						break;
					}
				} while (i == random_vertex || edges[i][random_vertex] != 0
						|| graph->list[random_vertex].weight >= max_degrees);
			}
			if(hack == 1){
				PRINT_TEXT("\nHACK HAS KICKED IN");
				do {
					random_vertex = rand() % MAX_VERTICES;
				} while (i == random_vertex);
			}
			edges[i][random_vertex] = edges[random_vertex][i] = 1;
//			PRINT_TEXT_VALUE("Adding Edge", random_vertex);
			int weight = rand() % MAX_WEIGHT_EDGE;
			struct Node *new = malloc(sizeof(struct Node));

			new->vertex = random_vertex;
			new->weight = weight;
			new->next = graph->list[i].next;
			graph->list[i].next = new;
			graph->list[i].weight++;

			new = malloc(sizeof(struct Node));
			new->vertex = i;
			new->weight = weight;
			new->next = graph->list[random_vertex].next;
			graph->list[random_vertex].next = new;
			graph->list[random_vertex].weight++;
		}
		if (i % 1000 == 0) {
			PRINT_TEXT_VALUE("\nOn VERTEX:", i);
		}
	}

	for (i = 0; i < MAX_VERTICES; i++)
		free(edges[i]);
	free(edges);

	printf("...Graph Filling Complete\n");
}

void generate_path(struct Graph* graph, int source_index, int target_index) {
	printf("...Generating Path...\n");
	PRINT_VALUE(source_index);
	int i, v, j;

	initialze_random_array(source_index, target_index);

	int vertex_index = source_index, random_vertex_index;
	struct Node* child_vertex;

	while ((random_vertex_index = get_random_vertex()) != -1) {
		link_creation(graph, vertex_index, random_vertex_index);
		vertex_index = random_vertex_index;
	}
	/*Link last random vertex to the target vertex*/
	link_creation(graph, vertex_index, target_index);
	printf("...Path Generating Complete\n");
}

void link_creation(struct Graph* graph, int source_index, int target_index) {
	PRINT_VALUE(target_index);
	struct Node* child_vertex;
	/*Searching whether the random index already exists in the children*/
	child_vertex = graph->list[source_index].next;
	while (child_vertex && child_vertex->vertex != target_index) {
		child_vertex = child_vertex->next;
	}
	/*If target vertex not exists in the child then replace one*/
	if (!child_vertex) {
		int weight = rand() % MAX_WEIGHT_EDGE;
		struct Node *new = malloc(sizeof(struct Node));
		new->vertex = target_index;
		new->weight = weight;
		new->next = graph->list[source_index].next;
		graph->list[source_index].next = new;

		new = malloc(sizeof(struct Node));
		new->vertex = source_index;
		new->weight = weight;
		new->next = graph->list[target_index].next;
		graph->list[target_index].next = new;
	}
}

void printGraph(struct Graph *g) {
	int i;
	struct Node *node;
	for (i = 0; i < g->totalVertices; i++) {
		printf("\nFor Vertex:%d Adjacent Nodes Are: ", i);
		node = g->list[i].next;
		while (node) {
			printf("(%d,%d) ", node->vertex, node->weight);
			node = node->next;
		}
	}
}

// int main(void) {
// clock_t start = clock();
// double cpu_time;
//
// struct Graph *graph = constructGraph();
// if (graph == NULL) {
// printf("Memory Allocation Failed");
// exit(1);
// }
//
// fillAdjacencyList(graph, 6);
// printGraph(graph);
//
// cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
// printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
// return EXIT_SUCCESS;
// }
