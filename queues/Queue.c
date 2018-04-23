#include <stdio.h>
#include "utilities.h"

int main(void) {
	// SNode *snode1, *snode2;
	// snode1 = snode2 = NULL;
	// stack_enqueue(&snode1, 2);
	// stack_enqueue(&snode1, 3);
	// stack_enqueue(&snode1, 4);
	// stack_enqueue(&snode1, 5);
	// stack_dequeue(&snode1, &snode2);
	// print_stack_queue(&snode1, &snode2);
	Queue *q = create_queue();
	en_queue(q, 1);
	en_queue(q, 2);
	de_queue(q);
	en_queue(q, 3);
	en_queue(q, 4);
	de_queue(q);
	print_queue(q);
	return 0;
}