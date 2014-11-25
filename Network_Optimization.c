/*
 ============================================================================
 Name        : Network_Optimization.c
 Author      : Akash
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Network_Optimization.h"

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

void generate_path(struct Graph* graph, int source_vertex, int target_vertex,
		int degrees) {
	printf("...Generating Path...\n");
	int i, v, j;

//	initialze_random_array(source_vertex, target_vertex);
//
//	int random_vertex_index = graph->list[source_vertex].next->vertex;
//	do {
//		struct Node* random_vertex = graph->list[random_vertex_index].next;
//		while (random_vertex && random_vertex->vertex != random_vertex) {
//			curr_vertex = curr_vertex->next;
//		}
//
//		if (!curr_vertex) {
//
//		}
//	} while ((random_vertex = get_random_vertex()) != -1);
//
//	for (i = 0; i < graph->totalVertices; i++) {
//		int values[graph->totalVertices];
//		memset(values, 0, graph->totalVertices * sizeof(int));
//		for (j = 0; j < 6; j++) {
//			do {
//				v = rand() % graph->totalVertices;
//			} while (values[v] != 0);
//			values[v] = 1;
//			struct Node *new = malloc(sizeof(struct Node));
//			new->vertex = v;
//			new->weight = rand() % MAX_WEIGHT_EDGE;
//			new->next = graph->list[i].next;
//			graph->list[i].next = new;
//		}
//	}
//	printf("...Graph Filling Complete\n");
}

int main(void) {
	clock_t start = clock();
	double cpu_time;

	struct Graph *graph = constructGraph();
	if (graph == NULL) {
		printf("Memory Allocation Failed");
		exit(1);
	}

	fillAdjacencyList(graph, 6);
	printGraph(graph);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return EXIT_SUCCESS;
}
