#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SNode {
	int data;
	struct SNode *next;
} SNode;

void stack_push(SNode **, int);
int stack_pop(SNode **);
bool is_stack_empty(SNode *);
int stack_peek(SNode *);

void stack_enqueue(SNode **, int);
void stack_dequeue(SNode **, SNode **);
void print_stack_queue(SNode **, SNode **);

SNode * create_new_snode(int data) {
	SNode *new_node = (SNode *)malloc(sizeof(SNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void stack_push(SNode **node, int data) {
	SNode *new_node = create_new_snode(data);
	//if(!*node) (*node) = new_node;
	//else {
		new_node->next = (*node);
		(*node) = new_node;
	//}
}

int stack_pop(SNode **node) {
	if(is_stack_empty(*node)) return -1;
	SNode *temp = *node;
	(*node) = temp->next;
	int data = temp->data;
	free(temp);
	return data;
}

bool is_stack_empty(SNode *node) {
	return node == NULL;
}

int stack_peek(SNode *node) {
	if(is_stack_empty(node)) return -1;
	return node->data;
}

void stack_enqueue(SNode **s1, int data) {
	stack_push(s1, data);
}

void stack_dequeue(SNode **s1, SNode **s2) {
	while(!is_stack_empty(*s1)) {
		stack_push(s2, stack_pop(s1));
	}
	stack_pop(s2);
	while(!is_stack_empty(*s2)) {
		stack_push(s1, stack_pop(s2));
	}
}

void print_stack_queue(SNode **s1, SNode **s2) {
	int temp;
	while(!is_stack_empty(*s1)) {
		temp = stack_pop(s1);
		printf("%d ", temp);
		stack_push(s2, temp);
	}
	while(!is_stack_empty(*s2)) {
		stack_push(s1, stack_pop(s2));
	}
}

int main(void) {
	SNode *snode1, *snode2;
	snode1 = snode2 = NULL;
	stack_enqueue(&snode1, 2);
	stack_enqueue(&snode1, 3);
	stack_enqueue(&snode1, 4);
	stack_enqueue(&snode1, 5);
	stack_dequeue(&snode1, &snode2);
	print_stack_queue(&snode1, &snode2);
	// printf("%d\n", snode1->data);
	return 0;
}