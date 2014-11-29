#include "Max_Capacity_Kruskal.h"

#ifndef MAX_CAPACITY_KRUSKAL_C_
#define MAX_CAPACITY_KRUSKAL_C_

double kruskal(struct Graph *graph, int source_vertex, int target_vertex) {
	PRINT_TEXT("_________________________________________________");
	PRINT_TEXT("...STARTING KRUSKAL...");
	clock_t start = clock();
	double cpu_time;
	int **adjacency_matrix = allocate_adjacency_matrix();
	int i, count = 0;

	struct Edge_Heap *heap = create_edge_heap();
	struct Node *node, *node2;
	for (i = 0; i < graph->totalVertices; i++) {
		node = graph->list[i].next;
		while (node) {
			if (adjacency_matrix[i][node->vertex] >= 0) {
				adjacency_matrix[node->vertex][i] = -1;
				insert_edge_heap(heap, i, node->vertex, node->weight);
				count++;
			}
			node = node->next;
		}
	}

	PRINT_TEXT("HEAP INSERTIONS DONE");
	PRINT_TEXT_VALUE("TOTAL:", count);

	struct Graph *new_graph = constructGraph();
	struct Set_Arrays *set_data = make_set();
	count = 0;

	while (is_edge_heap_empty(heap) != TRUE) {
		struct Edge *edge = get_max(heap);
		printf("Considering: %d %d ", edge->vertex1, edge->vertex2);
		if (union_by_rank(set_data, edge->vertex1, edge->vertex2)) {
			count++;
			link_creation_with_weight(new_graph, edge->vertex1, edge->vertex2,
					edge->weight);
			link_creation_with_weight(new_graph, edge->vertex2, edge->vertex1,
					edge->weight);
			PRINT_TEXT("ADDED");
		}
		for (i = 0; i < MAX_VERTICES; i++) {
			PRINT_VALUE(set_data->dad[i])
		}

	}

	PRINT_TEXT_VALUE("TOTAL EDGES ADDED:", count);
	/*Not including max capacity finding using BFS in calculation*/
	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;

	printGraph(new_graph);
	print_max_capacity_path_krukskal(new_graph, source_vertex, target_vertex);

	printf("Total Time Taken: %f\n", cpu_time);
	PRINT_TEXT("...KRUSKAL DONE...");
	PRINT_TEXT("_________________________________________________");

	for (i = 0; i < MAX_VERTICES; i++)
		free(adjacency_matrix[i]);
	free(adjacency_matrix);

	return cpu_time;
}
void print_max_capacity_path_krukskal(struct Graph* graph, int source_vertex,
		int target_vertex) {
	struct BFS_Result* bfs_result = breadth_first_search(graph, source_vertex,
			target_vertex);

	int vertex = target_vertex;
	PRINT_TEXT_VALUE("PRINTING PATH:", vertex);
	while (bfs_result->path[vertex] != vertex) {
		PRINT_VALUE(bfs_result->path[vertex]);
		vertex = bfs_result->path[vertex];
	}
	PRINT_TEXT_VALUE("MAX_CAPACITY PATH:", bfs_result->max_capacity);
}

struct BFS_Result* breadth_first_search(struct Graph* graph, int source_vertex,
		int target_vertex) {
	int visited[MAX_VERTICES], i, prev_vertex, max_capacity = INT_MAX;
	struct Node *node;
	struct BFS_Result *bfs_result = malloc(sizeof(struct BFS_Result));
	int *path = malloc(sizeof(int) * MAX_VERTICES);
	memset(visited, 0, sizeof(int) * MAX_VERTICES);
	for (i = 0; i < MAX_VERTICES; i++)
		path[i] = -1;

	struct Queue * queue = create_queue(MAX_VERTICES);
	enqueue(queue, source_vertex);
	prev_vertex = source_vertex;
	path[source_vertex] = prev_vertex;

	while (is_empty_queue(queue) != TRUE) {
		i = dequeue(queue);
		node = graph->list[i].next;
		while (node) {
			if (path[node->vertex] == -1) {
				enqueue(queue, node->vertex);
				path[node->vertex] = i;
				if (max_capacity > node->weight)
					max_capacity = node->weight;
			}
			if (node->vertex == target_vertex)
				break;
			node = node->next;
		}
	}
	bfs_result->path = path;
	bfs_result->max_capacity = max_capacity;
	return bfs_result;
}

int main() {
	clock_t start = clock();
	double cpu_time;
	srand(time(NULL));
	struct Graph *graph = generate_graph_type_1();

//	printGraph(graph);
	generate_path(graph, 0, 1);
	printGraph(graph);

	kruskal(graph, 0, 1);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return EXIT_SUCCESS;
}

#endif
