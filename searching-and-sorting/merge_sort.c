#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

void merge(int *a, int i, int m, int f) {
	int *temp1, *temp2, b = 0, c = 0, d = 0;
	temp1 = (int *)malloc((m-i+1)*sizeof(int));
	temp2 = (int *)malloc((f-m)*sizeof(int));
	for (int x = 0; x < m-i+1; ++x) temp1[x] = a[i + x];
	for (int x = 0; x < f-m; ++x) temp2[x] = a[m + 1 + x];
	while(b < m-i+1 && c < f-m) {
		if(temp1[b] < temp2[c]) { a[i + d] = temp1[b]; b++; }
		else { a[i + d] = temp2[c]; c++; }
		d++;
	}
	if(b == m-i+1) while(c < f-m) { a[i+d] = temp2[c]; c++; d++; }
	if(c == f-m) while(b < m-i+1) { a[i+d] = temp1[b]; b++; d++; }
	free(temp1);
	free(temp2);
}

void merge_sort(int *a, int i, int f) {
	if(i < f) {
		int m = (i+f)/2;
		merge_sort(a, i, m);
		merge_sort(a, m+1, f);
		merge(a, i, m, f);
	}
}

int main(void) {
	int a[] = {5, 4, 3, 2, 1}, n = sizeof(a)/sizeof(int);
	merge_sort(a, 0, n-1);
	print_array(a, n);
	return 0;
}