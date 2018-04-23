#include <stdio.h>
#include "utilities.h"

void max_heapify(int *a, int heapsize, int i) {
	int l, r, largest = i;
	l = left_child_index(i);
	r = right_child_index(i);
	if(l < heapsize && a[l] > a[i]) largest = l;
	if(r < heapsize && a[r] > a[largest]) largest = r;
	if(largest != i) {
		swap(&a[largest], &a[i]);
		max_heapify(a, heapsize, largest);
	}
}

void build_max_heap(int *a, int heapsize) {
	int i = heapsize/2-1;
	while(i >= 0) {
		max_heapify(a, heapsize, i);
		i--;
	}
}

void heap_sort(int *a, int n) {
	build_max_heap(a, n);
	for (int i = n-1; i > 0; --i)
	{
		swap(&a[0], &a[i]);
		build_max_heap(a, i);
	}
}

int main(void) {
	int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1}, n = sizeof(a)/sizeof(int);
	heap_sort(a, n);
	print_array(a, n);
	return 0;
}