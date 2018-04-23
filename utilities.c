#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "utilities.h"

/* print array utility function */
void print_array(int *a, int n) {
	int i = 0;
	while(i < n) printf("%d ", a[i++]);
	printf("\n");
}

void print_ll(LLNode *node) {
	while(node) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void free_up(LLNode *node) {
	if(node->next) free_up(node->next);
	else free(node);
}

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int left_child_index(int a) {
	return 2*a+1;
}

int right_child_index(int a) {
	return 2*a+2;
}

int gcd(int a, int b) {
	if(b == 0) return a;
	if(a < b) return gcd(b, a);
	return gcd(b, a%b);
}

/* Linked list helper functions */

LLNode * create_new_llnode(int data) {
	LLNode *new_node = (LLNode *)malloc(sizeof(LLNode *));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void insert_at_start(LLNode **head, int data) {
	LLNode *new_node = create_new_llnode(data);
	if(!*head) { /* linked list is empty */
		*head = new_node;
		return;
	}
	new_node->next = *head;
	*head = new_node;
}

void insert_at_end(LLNode *head, int data) {
	LLNode *new_node = create_new_llnode(data);
	if(!head) { /* linked list is empty */
		head = new_node;
		return;
	}
	while(head->next) head = head->next;
	head->next = new_node;
}

void insert_at_index(LLNode **head, int data, int index) {
	if(index == 0) { insert_at_start(head, data); return; }
	if(!*head) { printf("the linked list is empty\n"); return; } 
	LLNode *new_node = create_new_llnode(data), *temp = *head, *temp2;
	int count = 0;
	while(temp->next && count < index-1) {
		temp = temp->next;
		count++;
	}

	if(count != index-1) { printf("the length of linked list is smaller than index passed\n"); return; }

	temp2 = temp->next;
	temp->next = new_node;
	new_node->next = temp2;
}

void delete_by_key(LLNode **head, int data) {
	LLNode *temp = *head, *prev = NULL;
	if(!temp) { /* list is empty */
		printf("passed linked list is empty\n");
		return;
	}
	while(temp->data != data && temp->next) {
	    prev = temp;
	    temp = temp->next;
	}
	if(temp->data == data) {
		if(prev == NULL) {
			*head = temp->next;
		} else {
			prev->next = temp->next;
		}
		free(temp);
	}
	if(!temp->next) {
		printf("no node has key = %d in the linkedlist\n", data);
	}
}

void delete_by_index(LLNode **head, int index) {
	LLNode *temp = *head, *temp2;
	if(!temp) { /* list is empty */
		printf("passed linked list is empty\n");
		return;
	}
	if(index == 0) {
		*head = temp->next;
		free(temp);
		return;
	}
	int count = 0;
	while(temp->next && count < index - 1) {
	    temp = temp->next;
	    count++;
	}
	
	if(count != index-1) { printf("the length of linked list is smaller than index passed\n"); return; }

	temp2 = temp->next;
	temp->next = temp->next->next;
	free(temp2);
}

int ll_length_iterative(LLNode *node) {
	int count = 0;
	while(node) {
		node = node->next;
		count++;
	}
	return count;
}

int ll_length_recursive(LLNode *node) {
	if(node) return 1+ll_length_recursive(node->next);
	else return 0;
}

int ll_search_iterative(LLNode *node, int key) {
	int count = 0;
	while(node && node->data != key) {
		node = node->next;
		count++;
	}
	if(node && node->data == key) return count;
	return -1;
}

int ll_search_recursive(LLNode *node, int key) {
	static int index = 0;
	if(node && node->data == key) return index;
	else if(node && node->data != key) { index++; return ll_search_recursive(node->next, key); }
	else return -1;
} 

void ll_swap_nodes(LLNode **node, int key1, int key2) {
	if(key1 == key2) return;
	LLNode *temp1, *temp2, *prev1, *prev2;
	temp1 = temp2 = *node;
	prev1 = prev2 = NULL;
	while(temp1 && temp1->data != key1) {
		prev1 = temp1;
		temp1 = temp1->next;
	}
	while(temp2 && temp2->data != key2) {
		prev2 = temp2;
		temp2 = temp2->next;
	}
	if(!temp1 || !temp2) return;
	if(prev1 == NULL) {
		*node = temp2;
	} else {
		prev1->next = temp2;
	}

	if(prev2 == NULL) {
		*node = temp1;
	} else {
		prev2->next = temp1;
	}
	LLNode *temp = temp1->next;
	temp1->next = temp2->next;
	temp2->next = temp;
}

void ll_reverse(LLNode **node) {
	if(!*node) return;
	LLNode *temp = *node, *prev = NULL, *temp1;
	while(temp) {
		temp1 = temp->next; 
		temp->next = prev;
		prev = temp;
		temp = temp1; 
	}
	*node = prev;
}

bool ll_detect_cycle(LLNode *node) {
	LLNode *sptr, *fptr;
	sptr = fptr = node;
	while(sptr && fptr && fptr->next) {
		sptr = sptr->next;
		fptr = fptr->next->next;
		if(sptr == fptr) {
			return true;
		}
	}
	return false;
}

int ll_count_key(LLNode *node, int key) {
	int count = 0;
	while(node) {
		if(node->data == key) count++;
	    node = node->next;
	}
	return count;
}

/* stack functions begin */

CSNode * create_new_csnode(int data) {
	CSNode *new_node = (CSNode *)malloc(sizeof(CSNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

SNode * create_new_snode(int data) {
	SNode *new_node = (SNode *)malloc(sizeof(SNode));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void stack_push_c(CSNode **node, int data) {
	CSNode *new_node = create_new_csnode(data);
	new_node->next = (*node);
	(*node) = new_node;
}

void stack_push(SNode **node, int data) {
	SNode *new_node = create_new_snode(data);
	new_node->next = (*node);
	(*node) = new_node;
}

int stack_pop_c(CSNode **node) {
	if(is_stack_empty_c(*node)) return -1;
	CSNode *temp = *node;
	(*node) = temp->next;
	int data = temp->data;
	free(temp);
	return data;
}

int stack_pop(SNode **node) {
	if(is_stack_empty(*node)) return -1;
	SNode *temp = *node;
	(*node) = temp->next;
	int data = temp->data;
	free(temp);
	return data;
}

bool is_stack_empty_c(CSNode *node) {
	return node == NULL;
}

bool is_stack_empty(SNode *node) {
	return node == NULL;
}

int stack_peek_c(CSNode *node) {
	if(is_stack_empty_c(node)) return -1;
	return node->data;
}

int stack_peek(SNode *node) {
	if(is_stack_empty(node)) return -1;
	return node->data;
}

void infix_to_postfix(char *s) { /* we need operator stack when converting infix to postfix */
	int i = 0;
	// initialize empty stack
	CSNode *csnode = NULL;
	while(s[i] != '\0') {
		if(is_operand(s[i])) {
			printf("%c", s[i]);
		} else {
			if(is_stack_empty_c(csnode)) stack_push_c(&csnode, s[i]);
		}
		i++;
	}
}

bool is_operand(char ch) {
	return ((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z'));
}

int precedence(char op) {
	switch(op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

/* trees */

TNode *create_new_tnode(int data) {
	TNode *node = (TNode *)malloc(sizeof(TNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

/* searching elements closer to leafs, depth first search is better */

void preorder_traversal(TNode *root) {
	if(!root) return;
	printf("%d ", root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void inorder_traversal(TNode *root) {
	if(!root) return;
	inorder_traversal(root->left);
	printf("%d ", root->data);
	inorder_traversal(root->right);
}

void postorder_traversal(TNode *root) {
	if(!root) return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d ", root->data);
}

/* searching elements closer to root, breadth first search is better */

int tree_height(TNode *root) {
	if(!root) return 0;
	return 1 + max(tree_height(root->left), tree_height(root->right));
}

void _print_level(TNode *root, int level) {
	if(!root) return;
	if(level == 1) printf("%d ", root->data);
	else {
		_print_level(root->left, level-1);
		_print_level(root->right, level-1);
	}
}

void levelorder_traversal(TNode *root) {
	if(!root) return;
	int height = tree_height(root);
	for (int i = 1; i <= height; ++i)
	{
		_print_level(root, i);
	}
}

bool _is_leaf(TNode *node) {
	return !(node->left || node->right);
}

/* printing leaves from left to right */
void print_leaves(TNode *root) {
	if(!root) return;
	if(_is_leaf(root)) printf("%d ", root->data);
	print_leaves(root->left);
	print_leaves(root->right);
}

void print_internal_nodes(TNode *root) {
	if(!root) return;
	if(!_is_leaf(root)) printf("%d ", root->data);
	print_internal_nodes(root->left);
	print_internal_nodes(root->right);
}

void _find_hd_min_max(TNode *root, int *min, int *max, int hd) {
	if(!root) return;
	if(hd < *min) *min = hd;
	if(hd > *max) *max = hd;
	_find_hd_min_max(root->left, min, max, hd-1);
	_find_hd_min_max(root->right, min, max, hd+1);
}

void _print_vertical_level(TNode *root, int level) {
	if(!root) return;
	if(level == 0) printf("%d ", root->data);
	_print_vertical_level(root->left, level+1);
	_print_vertical_level(root->right, level-1);
}

void vertical_traversal(TNode *root) {
	int min, max;
	min = 0;
	max = 0;
	_find_hd_min_max(root, &min, &max, 0);
	for (int i = min; i <= max; ++i)
	{
		_print_vertical_level(root, i);
		printf("\n");
	}
}

void _print_top_view_nodes(TNode *root, int level) {
	if(!root) return;
	if(level == 0) { printf("%d ", root->data); return; }
	_print_top_view_nodes(root->left, level+1);
	_print_top_view_nodes(root->right, level-1);
}

void print_tree_top_view(TNode *root) {
	if(!root) return;
	int min, max;
	min = max = 0;
	_find_hd_min_max(root, &min, &max, 0);
	for (int i = min; i <= max; ++i)
	{
		_print_top_view_nodes(root, i);
	}
}

/* Queues */

QNode *create_new_qnode(int data) {
	QNode *qnode = (QNode *)malloc(sizeof(QNode));
	qnode->data = data;
	qnode->next = NULL;
	return qnode;
}

Queue *create_queue(void) {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void en_queue(Queue *q, int data) {
	QNode *qnode = create_new_qnode(data);
	if(!q) return;
	if(q->rear == NULL) {
		q->front = q->rear = qnode;
		return;
	}
	q->rear->next = qnode;
	q->rear = qnode;
}

int de_queue(Queue *q) {
	if(!q || is_queue_empty(q)) return -1;
	QNode *temp = q->front;
	int data = temp->data;
	if(q->front == q->rear) q->rear = temp->next;
	q->front = temp->next;
	free(temp);
	return data;
}

bool is_queue_empty(Queue *q) {
	return !q->front && !q->rear;
}

void print_queue(Queue *q) {
	QNode *temp = q->front;
	while(temp != q->rear) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", q->rear->data);
	printf("\n");
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
		stack_push(s2, stack_pop(s1));
	}
	while(!is_stack_empty(*s2)) {
		temp = stack_pop(s2);
		printf("%d ", temp);
		stack_push(s1, temp);
	}
	printf("\n");
}


/* graphs */

Graph * create_graph(int vertices) {
	Graph * graph = (Graph *)malloc(sizeof(Graph));
	graph->V = vertices;
	graph->adjlist = (AdjList *)malloc(graph->V*sizeof(AdjList));
	for (int i = 0; i < graph->V; ++i)
	{
		graph->adjlist[i].head = NULL;
		graph->adjlist[i].rear = NULL;
	}
	return graph;
}

ALNode * create_alnode(int data) {
	ALNode * alnode = (ALNode *)malloc(sizeof(ALNode));
	alnode->vertex = data;
	alnode->next = NULL;
	return alnode;
}

void add_directed_edge(Graph *graph, int src, int dest) {
	ALNode * alnode = create_alnode(dest);
	if(!graph->adjlist[src-1].head) {
		graph->adjlist[src-1].head = graph->adjlist[src-1].rear = alnode;
		return;
	}
	graph->adjlist[src-1].rear->next = alnode;
	graph->adjlist[src-1].rear = alnode;
}

void add_undirected_edge(Graph *graph, int src, int dest) {
	ALNode * alnode1 = create_alnode(dest);
	if(!graph->adjlist[src-1].head) {
		graph->adjlist[src-1].head = graph->adjlist[src-1].rear = alnode1;
	} else {
		graph->adjlist[src-1].rear->next = alnode1;
		graph->adjlist[src-1].rear = alnode1;
	}
	ALNode * alnode2 = create_alnode(src);
	if(!graph->adjlist[dest-1].head) {
		graph->adjlist[dest-1].head = graph->adjlist[dest-1].rear = alnode2;
	} else {
		graph->adjlist[dest-1].rear->next = alnode2;
		graph->adjlist[dest-1].rear = alnode2;
	}
}

void print_bfs_traversal(Graph *graph, int source_vertex) {
	Queue * q = create_queue();
	int * visited = (int *)calloc(graph->V, sizeof(int)), vertex;
	printf("%d ", source_vertex);
	visited[source_vertex-1] = 1;
	en_queue(q, source_vertex);
	while(!is_queue_empty(q)) {
		vertex = de_queue(q);
		ALNode *alnode = graph->adjlist[vertex-1].head;
		while(alnode != NULL) {
			if(visited[alnode->vertex-1] == 0) {
				printf("%d ", alnode->vertex);
				visited[alnode->vertex-1] = 1;
				en_queue(q, alnode->vertex);
			}
			alnode = alnode->next;
		}
	}
	printf("\n");
}

void _dfs_util(Graph *graph, int vertex, int *visited) {
	ALNode *alnode = graph->adjlist[vertex-1].head;
	while(alnode != NULL) {
		if(visited[alnode->vertex-1] == 0) {
			visited[alnode->vertex-1] = 1;
			printf("%d ", alnode->vertex);
			_dfs_util(graph, alnode->vertex, visited);
		}
		alnode = alnode->next;
	}
}

void print_dfs_traversal(Graph *graph, int source_vertex) {
	int * visited = (int *)calloc(graph->V, sizeof(int));
	visited[source_vertex-1] = 1;
	printf("%d ", source_vertex);
	_dfs_util(graph, source_vertex, visited);
	printf("\n");
}

/**
Longest Path Problem in DAG
In a general graph, Longest Path Problem is NP-Hard problem.
**/


/**
Shortest Path Problem in DAG
**/


/**
Topological sorting in DAG
Topological sorting is not possible if a graph is not DAG
**/

void _topological_sort_util(Graph *graph, int i, int *visited, int *sorted_array) {
	static int index = 0;
	visited[i] = 1;
	ALNode *alnode = graph->adjlist[i].head;
	while(alnode != NULL) {
		if(visited[alnode->vertex-1] == 0) _topological_sort_util(graph, alnode->vertex-1, visited, sorted_array);
		alnode = alnode->next;
	}
	sorted_array[index++] = i+1;
}

int * topological_sort(Graph *graph) {
	int * visited = (int *)calloc(graph->V, sizeof(int));
	int * sorted_array = (int *)calloc(graph->V, sizeof(int));
	for (int i = 0; i < graph->V; ++i) {
		_topological_sort_util(graph, i, visited, sorted_array);
	}
	return sorted_array;
}

/* Heaps */

int parent(int i) {
	return (i-1)/2;
}

int left_child(int i) {
	return 2*i+1;
}

int right_child(int i) {
	return 2*i+2;
}

void max_heapify(int *heap, int index, int heap_size) {
	int left, right, max_value, max_index;
	left = left_child(index);
	right = right_child(index);
	max_value = heap[index];
	max_index = index;
	if(heap_size > left && heap[left] > heap[index]) { max_value = heap[left]; max_index = left; }
	if(heap_size > right && heap[right] > max_value) { max_value = heap[right]; max_index = right; }
	if(index != max_index) {
		swap(&heap[max_index], &heap[index]);
		max_heapify(heap, max_index, heap_size);
	}
}

void min_heapify(int *heap, int index, int heap_size) {
	int left, right, min_value, min_index;
	left = left_child(index);
	right = right_child(index);
	min_value = heap[index];
	min_index = index;
	if(heap_size > left && heap[left] < heap[index]) { min_value = heap[left]; min_index = left; }
	if(heap_size > right && heap[right] < min_value) { min_value = heap[right]; min_index = right; }
	if(min_index != index) {
		swap(&heap[min_index], &heap[index]);
		min_heapify(heap, min_index, heap_size);
	}
}

void build_min_heap(int *heap, int heap_size) {
	int i = heap_size/2 - 1;
	while(i >= 0) {
		min_heapify(heap, i, heap_size);
		i--;
	}
}

void build_max_heap(int *heap, int heap_size) {
	int i = heap_size/2 - 1;
	while(i >= 0) {
		max_heapify(heap, i, heap_size);
		i--;
	}
}

void minheap_insert_key(int *heap, int key, int *heap_size) {
	heap[*heap_size] = key;
	(*heap_size)++;
	build_min_heap(heap, *heap_size);
}

void minheap_delete_key(int *heap, int index, int *heap_size) {
	minheap_decrease_key(heap, index, INT_MIN);
	minheap_extract_min(heap, heap_size);
}

/**
Precedence of prefix ++ and * is same. Associativity of both is from right to left.
Precedence of postfix ++ is higher than both prefix ++ and *. Associativity of postfix ++ is from left to right.
**/

int minheap_extract_min(int *heap, int *heap_size) {
	int min = heap[0];
	heap[0] = heap[*heap_size-1];
	(*heap_size)--;
	build_min_heap(heap, *heap_size);
	return min;
}

// int maxheap_extract_max(int *);

int minheap_get_min(int *heap) {
	return heap[0];
}

// int maxheap_get_max(int *);

/* decrease the key to new_val */
void minheap_decrease_key(int *heap, int index, int new_val) {
	heap[index] = new_val;
	while(index != 0 && parent(index) > heap[index]) {
		swap(&heap[parent(index)], &heap[index]);
		index = parent(index);
	}
}

void heap_sort(int *heap, int heap_size) {
	build_max_heap(heap, heap_size);
	for (int i = heap_size-1; i > 0; --i)
	{
		swap(&heap[0], &heap[i]);
		build_max_heap(heap, i);
	}
}












