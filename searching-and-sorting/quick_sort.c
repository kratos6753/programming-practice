#include <stdio.h>
#include "utilities.h"

int partition(int *a, int i, int f, int pivot) {
	int x, y;
	x = y = i;
	while(y < f) {
		if(a[y] < a[pivot]) { swap(&a[x], &a[y]); x++; }
		y++;
	}
	swap(&a[x], &a[pivot]);
	return x;
}

void quick_sort(int *a, int i, int f) {
	if(i < f) {
		int pivot = f, m;
		m = partition(a, i, f, pivot);
		quick_sort(a, i, m-1);
		quick_sort(a, m+1, f);
	}
}

int main(void) {
	int a[] = {5, 4, 3, 2, 1}, n = sizeof(a)/sizeof(int);
	quick_sort(a, 0, n-1);
	print_array(a, n);
	return 0;
}