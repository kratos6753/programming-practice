#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"

int main(void) {
	LLNode *head = NULL;
	LLNode *second = NULL;
	LLNode *third = NULL;

	/* The three nodes are created but are not allocated any space, to prove this try printing the address of node */

	printf("address of head = %p\n", head); /* it will print 0x0 i.e; memory not allocated yet */

	head = (LLNode *)malloc(sizeof(LLNode));
	second = (LLNode *)malloc(sizeof(LLNode));
	third = (LLNode *)malloc(sizeof(LLNode));

	printf("address of head = %p\n", head); /* it will now print proper memory location of the node */

	printf("sizeof int = %d\n", (int)sizeof(int)); /* int size = 4bytes */
	printf("sizeof node = %d\n", (int)sizeof(LLNode)); /* int size + padding + node pointer size = 16bytes */
	printf("sizeof node pointer = %d\n", (int)sizeof(head)); /* no. of bytes occupied by linkedlist node (8 bytes for 64bit) */

	/* Now we can start populating nodes */

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	// print_ll(head);

	free_up(head);


	LLNode *node = NULL;
	for (int i = 0; i < 10; ++i)
	{
		insert_at_index(&node, i+1, i);
	}
	print_ll(node);
	ll_swap_nodes(&node, 1, 5);
	print_ll(node);
	ll_reverse(&node);
	print_ll(node);
	bool detect_cycle = ll_detect_cycle(node);
	if(detect_cycle) {
		printf("cycle exists\n");
	} else {
		printf("cycle does not exist\n");
	}

	free_up(node);
	
	return 0;
}