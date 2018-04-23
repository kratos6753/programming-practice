#include <stdio.h>

int linear_search(int *a, int n, int key) {
	int i = 0;
	while(i < n) {
		if(a[i] == key) return i;
		i++;
	}
	return -1;
}

int main(void) {
	int a[] = {2, 3, 1, 5, 4}, key = 5, n = sizeof(a)/sizeof(int);
	int index = linear_search(a, n, key);
	if(index == -1) { printf("the key %d is not found in the array\n", key);  return 0; }
	printf("the key %d is found at index %d in the array\n", key, index);
	return 0;
}