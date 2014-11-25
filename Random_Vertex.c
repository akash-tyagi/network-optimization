#include "Random_Vertex.h"

void initialze_random_array(int source_vertex, int target_vertex) {
	if (random_array != NULL) {
		free(random_array);
	}

	random_array = malloc(sizeof(int) * MAX_VERTICES);
	int i = 0;
	while (i < MAX_VERTICES) {
		random_array[i] = i++;
	}
	swap_array_elements(random_array, source_vertex, MAX_VERTICES - 1);
	swap_array_elements(random_array, target_vertex, MAX_VERTICES - 2);
	random_array_size = MAX_VERTICES - 2;
}

int get_random_vertex() {
	if (random_array_size <= 0) {
		return -1;
	}
	time_t t;
	srand((unsigned) time(&t));
	int random_vertex = rand() % random_array_size;
	swap_array_elements(random_array, random_vertex, random_array_size - 1);
	random_array_size--;
	return random_array[random_array_size];
}

void swap_array_elements(int *arr, int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
