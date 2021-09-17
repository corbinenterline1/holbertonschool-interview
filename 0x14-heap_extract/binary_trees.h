#ifndef BINARY_TREES_H
#define BINARY_TREES_H
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;


void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);
int height_finder(heap_t *node, int height);
void node_handler(heap_t *node);
heap_t *tree_top(heap_t *node, int height, int node_height);

#endif
