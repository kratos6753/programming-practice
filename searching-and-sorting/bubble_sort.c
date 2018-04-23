#include <stdio.h>
#include "utilities.h"

void bubble_sort(int *a, int n) {
	int i = 0, j, swapped;
	while(i < n) {
		j = 1;
		swapped = 0;
		while(j < n) {
			if(a[j] < a[j-1]) { swap(&a[j], &a[j-1]); swapped = 1; }
			j++;
		}
		if(swapped == 0) return;
		i++;
	}
}

int main(void) {
	int a[] = {5, 4, 3, 2, 1}, n = sizeof(a)/sizeof(int);
	bubble_sort(a, n);
	print_array(a, n);
	return 0;
}