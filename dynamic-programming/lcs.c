#include <stdio.h>
#include <stdlib.h>

int *lcs_table;

int max(int a, int b) {
	return a > b ? a : b;
}

void build_lcs_table(char a[], char b[], int m, int n) {
	lcs_table = (int *)malloc((m+1)*(n+1)*sizeof(int));
	for (int i = 0; i < n; ++i)
		*(lcs_table + 0*n + i) = 0;
	for (int i = 0; i < m; ++i)
		*(lcs_table + i*n + 0) = 0;
}

void lcs(char a[], char b[], int m, int n) {
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if(a[i] == b[j]) *(lcs_table + (i+1)*n + j+1) = 1 + *(lcs_table + i*n + j);
			else *(lcs_table + (i+1)*n + j+1) = max(*(lcs_table + (i+1)*n + j), *(lcs_table + i*n + j+1));
		}
	}
}

void print_2d_array(void) {
	int m, n;
	m = 7;
	n = 5;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", *(lcs_table + i*n + j));
		}
		printf("\n");
	}
}

int main(void) {
	char a[] = "abcdfa";
	char b[] = "acda";
	build_lcs_table(a, b, 6, 4);
	lcs(a, b, 6, 4);
	int length = *(lcs_table + 4*5 + 3);
	printf("%d\n", length);
	print_2d_array();
	free(lcs_table);
	return 0;
}