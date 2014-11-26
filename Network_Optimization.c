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

void generate_path(struct Graph* graph, int source_index, int target_index) {
	printf("...Generating Path...\n");
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

void link_creation(struct Graph* graph, int source_vertex, int target_vertex) {
	struct Node* child_vertex;
	/*Searching whether the random index already exists in the children*/
	child_vertex = graph->list[source_vertex].next;
	while (child_vertex && child_vertex->vertex != target_vertex) {
		child_vertex = child_vertex->next;
	}
	/*If target vertex not exists in the child then replace one*/
	if (!child_vertex) {
		child_vertex = graph->list[source_vertex].next;
		child_vertex->vertex = target_vertex;
	}
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
