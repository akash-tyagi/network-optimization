/*
 * Using Adjacency List to represent graph
 * Node : represents the edges in the graph 
 * Graph: stores the pointers to each vertex in the graph
 */
#include "Graph.h"

#ifndef GRAPH_C_
#define GRAPH_C_

struct Graph* generate_graph_type_1() {
	struct Graph *graph = construct_graph();
	fill_adjacency_list(graph, TYPE_1_DEGREE);
	return graph;
}

struct Graph* generate_graph_type_2() {
	struct Graph *graph = construct_graph();
	fill_adjacency_list(graph, TYPE_2_DEGREE);
	return graph;
}

struct Graph* construct_graph() {
	int i = 0;
	struct Graph *graph = malloc(sizeof(struct Graph));
	if (graph == NULL) {
		PRINT_TEXT("GRAPH ALLOCATION FAILED!!");
		exit(EXIT_FAILURE);
	}

	graph->totalVertices = MAX_VERTICES;
	graph->list = malloc(sizeof(struct Node) * graph->totalVertices);
	if (graph->list == NULL) {
		PRINT_TEXT("GRAPH VERTICES ALLOCATION FAILED!!");
		exit(EXIT_FAILURE);
	}

	while (i < graph->totalVertices) {
		graph->list[i].vertex = i;
		/*this particular weight is used as edge count for vertex*/
		graph->list[i].weight = 0;
		graph->list[i].next = NULL;
		i++;
	}

	return graph;
}

int** allocate_2D_matrix(int rows, int cols) {
	int i;
	int **matrix = (int **) malloc(rows * sizeof(int *));
	if (matrix == NULL) {
		PRINT_TEXT("2D MATRIX MEMORY ALLOCATION FAILED!!");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < rows; i++) {
		matrix[i] = malloc(cols * sizeof(int));
		memset(matrix[i], 0, cols * sizeof(int));
		if (matrix[i] == NULL) {
			PRINT_TEXT("2D MATRIX MEMORY ALLOCATION FAILED!!");
			exit(EXIT_FAILURE);
		}
	}
	return matrix;
}

int get_vertex(struct Graph *graph, int *is_random_empty,
		int **adjacency_matrix, int max_degrees, int vertex) {
	int random_vertex;
	if (*is_random_empty == 0) {
		do {
			random_vertex = get_random_vertex();
			/*Random generator out of options*/
			if (random_vertex == -1) {
				*is_random_empty = 1;
				break;
			}
		} while (vertex == random_vertex
				|| adjacency_matrix[vertex][random_vertex] != 0
				|| graph->list[random_vertex].weight >= max_degrees);
	} else {
		random_vertex = -1;
	}
	return random_vertex;
}

void fill_adjacency_list(struct Graph *graph, int max_degrees) {
	printf("...Filling List...\n");

	/*Use to avoid multiple edges generation between same vertices*/
	int **adjacency_matrix = allocate_2D_matrix(MAX_VERTICES, MAX_VERTICES);
	int vertex, random_vertex, j;

	/*Edge generation using leads to creation of
	 * forests. So, when my random function get out of options,
	 * traditional random function is used */
	int is_random_empty = 0;

	for (vertex = 0; vertex < graph->totalVertices; vertex++) {
		if (vertex % 1000 == 0) {
			PRINT_TEXT_VALUE("ON VERTEX:", vertex);
		}
		is_random_empty = 0;
		initialze_random_array2(vertex);
		j = graph->list[vertex].weight;
		while (j < max_degrees) {
			j++;
			random_vertex = get_vertex(graph, &is_random_empty,
					adjacency_matrix, max_degrees, vertex);
			if (random_vertex == -1)
				continue;
			adjacency_matrix[vertex][random_vertex] =
					adjacency_matrix[random_vertex][vertex] = 1;

			/*Create edges for undirected graph, hence two vertices */
			int weight = rand() % MAX_WEIGHT_EDGE + 1;
			struct Node *new = malloc(sizeof(struct Node));
			new->vertex = random_vertex;
			new->weight = weight;
			new->next = graph->list[vertex].next;
			graph->list[vertex].next = new;
			graph->list[vertex].weight++;

			new = malloc(sizeof(struct Node));
			new->vertex = vertex;
			new->weight = weight;
			new->next = graph->list[random_vertex].next;
			graph->list[random_vertex].next = new;
			graph->list[random_vertex].weight++;
		}
	}

	for (j = 0; j < MAX_VERTICES; j++)
		free(adjacency_matrix[j]);
	free(adjacency_matrix);
}

void generate_path(struct Graph* graph, int source_index, int target_index) {
	printf("...Generating Path...\n");
	int i, v, j;

	initialze_random_array(source_index, target_index);
	int vertex_index = source_index, random_vertex_index;

	while ((random_vertex_index = get_random_vertex()) != -1) {
		link_creation(graph, vertex_index, random_vertex_index);
		vertex_index = random_vertex_index;
	}

	/*Link last random vertex to the target vertex*/
	link_creation(graph, vertex_index, target_index);
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
		int weight = rand() % MAX_WEIGHT_EDGE + 1;
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

void print_graph(struct Graph *g) {
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
