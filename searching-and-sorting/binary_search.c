#include <stdio.h>

int binary_search(int *a, int f, int l, int key) {
	if(f < l) {
		int m = (f+l)/2;
		if(a[m] == key) return m;
		if(a[m] < key) return binary_search(a, m+1, l, key);
		return binary_search(a, f, m-1, key);
	} else return -1;
}

int main(void) {
	int a[] = {1, 2, 3, 4, 5, 6, 7}, key = 8, f= 0, l = sizeof(a)/sizeof(int)-1;
	int index = binary_search(a, f, l, key);
	if(index == -1) { printf("the key %d is not found in the array\n", key); return 0; }
	printf("the key %d is found at index %d in the array\n", key, index);
	return 0;
}