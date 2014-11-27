#include "Max_Capacity_Kruskal.h"
void kruskal(struct Graph *graph, int source_vertex, int target_vertex) {
	int i, count = 0;
	struct Heap *heap = create();
	struct Node *node;
	for (i = 0; i < graph->totalVertices; i++) {
		node = graph->list[i].next;
		while (node) {
			insert_heap(heap, i, node->vertex, node->weight);
			node = node->next;
			count++;
		}
	}
	PRINT_TEXT_VALUE("\nTOTAL:", count);

	struct Graph *new_graph = constructGraph();
	int vertices[MAX_VERTICES];
	for (i = 0; i < MAX_VERTICES; i++)
		vertices[i] = i;
	count = 0;

	while (is_heap_empty(heap) != TRUE) {
		struct Edge *edge = get_min_max(heap);
//		printf("Considering: %d %d ", edge->vertex1, edge->vertex2);
		int root1 = edge->vertex1, root2 = edge->vertex2;
		while (vertices[root1] != root1)
			root1 = vertices[root1];
		while (vertices[root2] != root2)
			root2 = vertices[root2];
//		PRINT_VALUES(root1, root2);
		//set operations
		if (root1 == root2) {
			continue;
		} else {
			vertices[root2] = root1;
		}
		count++;
		link_creation_with_weight(new_graph, edge->vertex1, edge->vertex2,
				edge->weight);
		link_creation_with_weight(new_graph, edge->vertex2, edge->vertex1,
				edge->weight);
//		for (i = 0; i < MAX_VERTICES; i++) {
//			PRINT_VALUE(vertices[i])
//		}
//		PRINT_TEXT("ADDED");
	}

	PRINT_TEXT_VALUE("TOTAL EDGES ADDED:", count);
	printGraph(new_graph);

	struct BFS_Result* bfs_result = breadth_first_search(new_graph,
			source_vertex, target_vertex);

	int vertex = target_vertex;
	PRINT_TEXT_VALUE("PRINTING PATH:", vertex);
	while (bfs_result->path[vertex] != vertex) {
		PRINT_VALUE(bfs_result->path[vertex]);
		vertex = bfs_result->path[vertex];
	}
	PRINT_TEXT_VALUE("\nMAX_CAPACITY PATH:", bfs_result->max_capacity);
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
	generate_path(graph, 0, 4);
//	printGraph(graph);

	kruskal(graph, 0, 4);

	cpu_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
	printf("\n\nTotal Time Taken: %f\n\n", cpu_time);
	return EXIT_SUCCESS;
}

