#include <stdbool.h>

void print_array(int *, int );
void swap(int *, int *);
int left_child_index(int);
int right_child_index(int);
int gcd(int, int);

typedef struct Node { /* to remove structure padding use __attribute__((__packed__)) after struct keyword in the definition */
	int data;
	struct Node *next;
} LLNode;
typedef struct CSNode {
	char data;
	struct CSNode *next;
} CSNode;
typedef struct SNode {
	int data;
	struct SNode *next;
} SNode;
typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
} TNode;
typedef struct QNode {
	int data;
	struct QNode *next;
} QNode;
typedef struct Queue {
	QNode *front, *rear;
} Queue;

typedef struct AdjListNode {
	int vertex; // vertex number
	struct AdjListNode *next;
} ALNode;
typedef struct AdjList {
	ALNode *head, *rear;
} AdjList;
typedef struct Graph {
	int V; // no.of vertices in the graph
	AdjList *adjlist;
} Graph;

void print_ll(LLNode *);
LLNode * create_new_llnode(int);
void insert_at_start(LLNode **, int);
void insert_at_end(LLNode *, int);
void insert_at_index(LLNode **, int, int);
void delete_by_key(LLNode **, int);
void delete_by_index(LLNode **, int);
int ll_length_recursive(LLNode *);
int ll_length_iterative(LLNode *);
int ll_search_recursive(LLNode *, int);
int ll_search_iterative(LLNode *, int);
void ll_swap_nodes(LLNode **, int, int);
void ll_reverse(LLNode **);
bool ll_detect_cycle(LLNode *);

void stack_push_c(CSNode **, int);
int stack_pop_c(CSNode **);
bool is_stack_empty_c(CSNode *);
int stack_peek_c(CSNode *);

void stack_push(SNode **, int);
int stack_pop(SNode **);
bool is_stack_empty(SNode *);
int stack_peek(SNode *);

bool is_operand(char);

void free_up(LLNode *node);

TNode *create_new_tnode(int);
void preorder_traversal(TNode *);
void inorder_traversal(TNode *);
void postorder_traversal(TNode *);
int tree_height(TNode *);
void levelorder_traversal(TNode *);
void print_leaves(TNode *);
void print_internal_nodes(TNode *);
void vertical_traversal(TNode *);
void print_tree_top_view(TNode *);
void print_tree_bottom_view(TNode *);

QNode *create_new_qnode(int);
Queue *create_queue(void);
void en_queue(Queue *, int);
int de_queue(Queue *);
void print_queue(Queue *);
bool is_queue_empty(Queue *);

void stack_enqueue(SNode **, int);
void stack_dequeue(SNode **, SNode **);
void print_stack_queue(SNode **, SNode **);

Graph * create_graph(int);
void add_directed_edge(Graph *, int, int);
void add_undirected_edge(Graph *, int, int);
void print_bfs_traversal(Graph *, int);
void print_dfs_traversal(Graph *, int);
int * topological_sort(Graph *);

void min_heapify(int *, int, int);
void build_min_heap(int *, int);
void max_heapify(int *, int, int);
void build_max_heap(int *, int);
void minheap_insert_key(int *, int, int *);
void minheap_delete_key(int *, int, int *);
int minheap_extract_min(int *, int *);
int maxheap_extract_max(int *);
int minheap_get_min(int *);
int maxheap_get_max(int *);
void minheap_decrease_key(int *, int, int);
int right_child(int); 
int left_child(int);
int parent(int);
void heap_sort(int *, int);











