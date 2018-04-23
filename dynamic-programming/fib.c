#include <stdio.h>
#define COUNT 100

int fib_table[COUNT];

int fib(long n) {
	if(n == 0 || n == 1) return fib_table[n] = n;
	else if(fib_table[n] != 0) return fib_table[n];
	else return fib_table[n] = fib(n-1) + fib(n-2);
}

int main(void) {
	printf("fib 10 = %d\n", fib(10));
	printf("fib 15 = %d\n", fib(15));
	return 0;
}