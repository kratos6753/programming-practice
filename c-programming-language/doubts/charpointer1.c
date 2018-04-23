#include <stdio.h>

// why are the addresses of char pointers not assigned after one pointer?
// possible reasons
// -> as first pointer length is not fixed, so rest of pointers no memory is allocated
// ----> the reason above is checked but found it is not true
int main(void) {
	int count = 0;
	char *s = (char *)malloc(100);
	char *p;
	char *z;
	printf("%p\n", s);
	printf("%p\n", p);
	printf("%p\n", z);
	return 0;
}