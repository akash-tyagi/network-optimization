#include "Set_Operations.h"
#ifndef SET_OPERATIONS_C_
#define SET_OPERATIONS_C_

struct Set_Arrays * make_set() {
	struct Set_Arrays *arrays = malloc(sizeof(struct Set_Arrays));
	arrays->dad = malloc(sizeof(int) * MAX_VERTICES);
	arrays->rank = malloc(sizeof(int) * MAX_VERTICES);
	int i = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		arrays->dad[i] = i;
	return arrays;
}

int find_by_rank(struct Set_Arrays *arrays, int vertex) {
	int temp1, temp2, root = vertex;
	while (arrays->dad[root] != root)
		root = arrays->dad[root];

	temp1 = vertex;

	while (arrays->dad[temp1] != root) {
		temp2 = arrays->dad[temp1];
		arrays->dad[temp1] = root;
		temp1 = temp2;
	}
	return root;
}

int union_by_rank(struct Set_Arrays *arrays, int vertex1, int vertex2) {
	int rank1 = find_by_rank(arrays, vertex1);
	int rank2 = find_by_rank(arrays, vertex2);

	if (arrays->dad[vertex1] == arrays->dad[vertex2]) {
		return FALSE;
	} else {
		if (rank1 > rank2) {
			arrays->dad[vertex2] = arrays->dad[vertex1];
		} else {
			arrays->dad[vertex1] = arrays->dad[vertex2];
		}
		if (rank1 == rank2) {
			arrays->rank[vertex2]++;
		}
	}
	return TRUE;
}

#endif /* SET_OPERATIONS_C_ */
