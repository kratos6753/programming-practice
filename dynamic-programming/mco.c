// Matrix Chain Multiplication Order

#include <stdio.h>
#include <limits.h>

int mco(int arr[], int n) {
	int m[n][n];
	int i, j, k, q, L;

	for (i = 0; i < n; ++i)
	{
		m[i][i] = 0;
	}

	for (L = 2; L < n; ++L)
	{
		for (i = 1; i < n-L+1; ++i)
		{
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k < j; ++k)
			{
				q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
				if(q < m[i][j]) m[i][j] = q;
			}
		}
	}

	return m[1][n-1];
}

int main(void) {
	int arr[] = {1, 2, 3, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	int multiplications = mco(arr, size);
	printf("%d\n", multiplications);
	return 0;
}