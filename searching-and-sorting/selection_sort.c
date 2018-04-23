#include <stdio.h>
#include <limits.h>
#include "utilities.h"

void selection_sort(int *a, int n) {
	int i = 0, j, min, min_index;
	while(i < n) {
		j = i;
		min = INT_MAX;
		while(j < n) {
			if(a[j] < min) { min = a[j]; min_index = j; }
			j++;
		}
		if(min_index != i) swap(&a[i], &a[min_index]);
		i++;
	}
}

int main(void) {
	int a[] = {5, 4, 3, 2, 1}, n = sizeof(a)/sizeof(int);
	selection_sort(a, n);
	print_array(a, n);
	return 0;
}