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

void initialze_random_array2(int source_vertex) {
	if (random_array != NULL) {
		free(random_array);
	}
	random_array = malloc(sizeof(int) * MAX_VERTICES);
	int i = 0;
	while (i < MAX_VERTICES) {
		random_array[i] = i++;
	}
	swap_array_elements(random_array, source_vertex, MAX_VERTICES - 1);
	random_array_size = MAX_VERTICES - 1;
}

int get_random_vertex() {
	if (random_array_size <= 0) {
//		PRINT_TEXT("\nRANDOM ARRAY EMPTY\n");
		return -1;
	}
	time_t t;
	srand((unsigned) time(&t));
	int random_vertex = rand() % random_array_size;
//	PRINT_TEXT_VALUE("RADOM VALUE:", random_vertex);
	swap_array_elements(random_array, random_vertex, random_array_size - 1);
	random_array_size--;
	return random_array[random_array_size];
}

void swap_array_elements(int *arr, int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

//int main() {
//	initialze_random_array(2,3);
//	int i=0;
//	printf("Random Array Size:%d\n",random_array_size);
//	printf("MAX_VERTICES:%d\n",MAX_VERTICES);
//	while(i<MAX_VERTICES-2){
//		printf("%d ",get_random_vertex());
//		i++;
//	}
//}
