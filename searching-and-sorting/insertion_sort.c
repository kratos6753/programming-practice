#include <stdio.h>
#include "utilities.h"

void insertion_sort(int *a, int n) {
	int i = 1, j, t;
	while(i < n) {
		j = i-1;
		t = a[i];
		while(j >= 0 && a[j] > t) { a[j+1] = a[j]; j--;}
		a[j+1] = t;
		i++;
	}
}

int main(void) {
	int a[] = {5, 4, 3, 2, 1}, n = sizeof(a)/sizeof(int);
	insertion_sort(a, n);
	print_array(a, n);
	return 0;
}