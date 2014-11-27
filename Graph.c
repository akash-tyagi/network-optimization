/*
 * Using Adjacency List to represent graph
 * Node : represents the edges in the graph 
 * Graph: stores the pointers to each vertex in the graph
 */
#include "Graph.h"

#ifndef GRAPH_C_
#define GRAPH_C_

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
	int i = 0;
	struct Graph *graph = malloc(sizeof(struct Graph));
	if (graph == NULL) {
		PRINT_TEXT("GRAPH ALLOCATION FAILED!!");
		exit(EXIT_FAILURE);
	}

	graph->totalVertices = MAX_VERTICES;
	graph->list = malloc(sizeof(struct Node) * graph->totalVertices);
	if (graph->list == NULL) {
		PRINT_TEXT("GRAPH ALLOCATION FAILED!!");
		exit(EXIT_FAILURE);
	}

	while (i < graph->totalVertices) {
		graph->list[i].vertex = i;
		/*weight in the source vertex is used as edge count*/
		graph->list[i].weight = 0;
		graph->list[i].next = NULL;
		i++;
	}

	printf("...Graph Construction Done...\n");
	return graph;
}

int** allocate_adjacency_matrix() {
	int i;
	int **adjacency_matrix = (int **) malloc(MAX_VERTICES * sizeof(int *));
	if (adjacency_matrix == NULL) {
		PRINT_TEXT("ADJACENCY FILLING FAILED!!");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < MAX_VERTICES; i++) {
		adjacency_matrix[i] = malloc(MAX_VERTICES * sizeof(int));
		if (adjacency_matrix[i] == NULL) {
			PRINT_TEXT("ADJACENCY FILLING FAILED!!");
			exit(EXIT_FAILURE);
		}
	}
	return adjacency_matrix;
}

void fillAdjacencyList(struct Graph *graph, int max_degrees) {
	printf("...Filling List...\n");
	int i, random_vertex, j;

	/*Used to avoid multiple edges between same vertices*/
	int **adjacency_matrix = allocate_adjacency_matrix();

	/*Graph generation using random can sometimes lead to creation of
	 * forests. So, when my random function get out of options,
	 * traditional random function is used */
	int is_random_empty = 0;

	for (i = 0; i < graph->totalVertices; i++) {
		PRINT_TEXT_VALUE("\nVERTEX:", i);
		is_random_empty = 0;
		initialze_random_array2(i);
		while (graph->list[i].weight < max_degrees) {
			if (is_random_empty == 0) {
				do {
					random_vertex = get_random_vertex();
					/*Random generator out of options*/
					if (random_vertex == -1) {
						is_random_empty = 1;
						break;
					}
				}while (i == random_vertex
						|| adjacency_matrix[i][random_vertex] != 0
						|| graph->list[random_vertex].weight >= max_degrees);
			}
			if (is_random_empty == 1) {
//				PRINT_TEXT("\nHACK HAS KICKED IN");
				do {
					random_vertex = rand() % MAX_VERTICES;
				}while (i == random_vertex);
			}

			adjacency_matrix[i][random_vertex] =
			adjacency_matrix[random_vertex][i] = 1;
//			PRINT_TEXT_VALUE("Adding Edge", random_vertex);

			/*Create edges for undirected graph, hence two vertices */
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
	}

	for (i = 0; i < MAX_VERTICES; i++)
	free(adjacency_matrix[i]);
	free(adjacency_matrix);

	printf("...Graph Filling Complete\n");
}

void generate_path(struct Graph* graph, int source_index, int target_index) {
	printf("...Generating Path...\n");
//	PRINT_VALUE(source_index);
	int i, v, j;

	initialze_random_array(source_index, target_index);
	int vertex_index = source_index, random_vertex_index;

	while ((random_vertex_index = get_random_vertex()) != -1) {
		link_creation(graph, vertex_index, random_vertex_index);
		vertex_index = random_vertex_index;
	}

	/*Link last random vertex to the target vertex*/
	link_creation(graph, vertex_index, target_index);
	printf("...Path Generating Complete\n");
}

void link_creation(struct Graph* graph, int source_index, int target_index) {
//	PRINT_VALUE(target_index);
	struct Node* child_vertex;

	/*Searching whether the random index already exists in the children*/
	child_vertex = graph->list[source_index].next;
	while (child_vertex && child_vertex->vertex != target_index) {
		child_vertex = child_vertex->next;
	}

	/*If target vertex not exists in the child create new edge*/
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

void link_creation_with_weight(struct Graph* graph, int source_index,
		int target_index, int weight) {
//	PRINT_VALUE(target_index);
	struct Node* child_vertex;

	/*Searching whether the random index already exists in the children*/
	child_vertex = graph->list[source_index].next;
	while (child_vertex && child_vertex->vertex != target_index) {
		child_vertex = child_vertex->next;
	}

	/*If target vertex does not exist in the adjacent nodes then create new edge*/
	if (!child_vertex) {
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
	struct Node *adjacent_vertex;
	for (i = 0; i < g->totalVertices; i++) {
		printf("\nFor Vertex:%d Adjacent Nodes Are: ", i);
		adjacent_vertex = g->list[i].next;
		while (adjacent_vertex) {
			printf("(%d,%d) ", adjacent_vertex->vertex,
					adjacent_vertex->weight);
			adjacent_vertex = adjacent_vertex->next;
		}
	}
}
//
//int main(void) {
//	clock_t start = clock();
//	double cpu_time;
//
//	struct Graph *graph = constructGraph();
//	if (graph == NULL) {
//		printf("Memory Allocation Failed");
//		exit(1);
//	}
//
//	fillAdjacencyList(graph, 6);
//	printGraph(graph);
//
//	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
//	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
//	return EXIT_SUCCESS;
//}

#endif
