#include<stdio.h>
#include<stdlib.h>

struct Heap {
    int *arr;
    int index;
    int size;
};

struct Heap* create(int size) {
    struct Heap *h = malloc(sizeof(struct Heap));
    if( h == NULL){
        printf("memory allocation failed");
        exit(1);
    }
    h->index = -1;
    h->size= size;
    h->arr = malloc(sizeof(int) * size);
    if(h->arr == NULL) {
        printf("memory allocation failed");
        exit(1);
    }
    return h;
}

int parentIndex(int index) {
    return (index - 1)/2;
}

int leftChildIndex(int index) {
    return 2*index + 1;
}

int rightChildIndex( int index) {
    return 2*index + 2;
}

void insert(struct Heap *h, int val) {
    if(h->index + 1 == h->size) {
        printf("Heap Insertion Failed\n");
        exit(1);
    }
    h->index++;
    h->arr[h->index] = val;
    h->size++;
    
    int index = h->size -1;
    //heap is built on top of edge weights or index??
    while (parentIndex(index) >= 0 && h->arr[parentIndex(index)]) {
    
    }   
}

int minimum(struct Heap *h) {
    if(h == NULL || h->size <= 0) {
        printf("Heap Does Not Exist\n");
        return -1;
    }
    return h->arr[0];
}


main() {

}
