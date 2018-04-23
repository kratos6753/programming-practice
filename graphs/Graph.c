#include <stdio.h>
#include "utilities.h"

int main(void) {
	Graph *g = create_graph(6); // 6
	// add_undirected_edge(g, 1, 3);
	// add_undirected_edge(g, 1, 2);
	// add_undirected_edge(g, 2, 4);
	// add_undirected_edge(g, 2, 5);
	// add_undirected_edge(g, 3, 5);
	// add_undirected_edge(g, 4, 5);
	// add_undirected_edge(g, 4, 6);
	// add_undirected_edge(g, 5, 6);
	// print_bfs_traversal(g, 1);
	
	// add_directed_edge(g, 1, 2);
	// add_directed_edge(g, 1, 3);
	// add_directed_edge(g, 3, 1);
	// add_directed_edge(g, 3, 4);
	// add_directed_edge(g, 4, 4);
	// add_directed_edge(g, 2, 3);
	// print_dfs_traversal(g, 3);

	add_directed_edge(g, 3, 4);
	add_directed_edge(g, 4, 2);
	add_directed_edge(g, 5, 1);
	add_directed_edge(g, 5, 2);
	add_directed_edge(g, 6, 1);
	add_directed_edge(g, 6, 3);
	int *sorted_array = topological_sort(g);
	print_array(sorted_array, g->V);
	return 0;
}