#include <stdio.h>
#include "utilities.h"
#define CAPACITY 20

/**
It supports insert, delete, extract max, decrease key in O(logn) time.
Binomial and fibonacci heap are variations of binary heaps which perform union effectively.
Priority Queues are used in Dijkstra's algo and Prim's algo
**/

int main(void) {
	int min_heap[CAPACITY];
	int heap_size = 0;
	minheap_insert_key(min_heap, 10, &heap_size);
	minheap_insert_key(min_heap, 8, &heap_size);
	minheap_insert_key(min_heap, 3, &heap_size);
	printf("Printing Min Heap:\n");
	print_array(min_heap, heap_size);
	printf("On Heap Sort:\n");
	heap_sort(min_heap, heap_size);
	print_array(min_heap, heap_size);
	return 0;
}