#include <stdio.h>
#include <stdbool.h>
#include "utilities.h"

int main(void) {
	LLNode *snode = NULL;
	stack_push(&snode, 2);
	stack_push(&snode, 3);
	stack_push(&snode, 4);
	stack_pop(&snode);
	printf("Element at top of the stack is %d\n", stack_peek(snode));
	bool is_empty = is_stack_empty(snode);
	if(is_empty) printf("Stack is empty\n");
	else printf("Stack is not empty\n"); 
	print_ll(snode); // prints stack from top to bottom
	return 0;
}