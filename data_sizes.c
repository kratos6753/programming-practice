#include <stdio.h>

int main(void) {
	int int_size = sizeof(int);
	int int_ptr_size = sizeof(int *);
	int float_size = sizeof(float);
	int float_ptr_size = sizeof(float *);
	int double_size = sizeof(double);
	int double_ptr_size = sizeof(double *);
	int char_size = sizeof(char);
	int char_ptr_size = sizeof(char *);
	printf("int size = %d\n", int_size);
	printf("int ptr size = %d\n", int_ptr_size);
	printf("float size = %d\n", float_size);
	printf("float ptr size = %d\n", float_ptr_size);
	printf("double size = %d\n", double_size);
	printf("double ptr size = %d\n", double_ptr_size);
	printf("char size = %d\n", char_size);
	printf("chat ptr size = %d\n", char_ptr_size);
	return 0;
}