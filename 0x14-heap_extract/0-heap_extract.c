#include "binary_trees.h"

/**
  * heap_extract - extract the root node of a max binary heap
  * @root: double pointer to root node of heap
  *
  * Return: value stored in node, 0 on fail
  */
int heap_extract(heap_t **root)
{
	int value, height;
	heap_t *top;

	if (root == NULL || (*root) == NULL)
		return (0);
	top = *root;
	value = top->n;
	if (top->left == NULL && top->right == NULL)
		*root = NULL;
	else
	{
		height = height_finder(*root, 1);
		top = tree_top(*root, height, 1);
		(*root)->n = top->n;
		if (top->parent->right == top)
			top->parent->right = NULL;
		else
			top->parent->left = NULL;
		node_handler(*root);
	}
	free(top);
	return (value);
}

/**
  * node_handler - Handles the node in the heap.
  * @node: Starting node.
  */
void node_handler(heap_t *node)
{
	int tmp;
	heap_t *max = node;

	if (node->left != NULL && node->left->n > max->n)
		max = node->left;
	if (node->right != NULL && node->right->n > max->n)
		max = node->right;
	if (max != node)
	{
		tmp = node->n;
		node->n = max->n;
		max->n = tmp;
		node_handler(max);
	}
}

/**
  * height_finder - Returns the height of the tree.
  * @node: Starting node.
  * @height: Height of starting node.
  *
  * Return: Height of the heap.
  */
int height_finder(heap_t *node, int height)
{
	int left, right;

	if (node == NULL)
		return (height - 1);
	height++;
	left = height_finder(node->left, height);
	right = height_finder(node->right, height);
	if (left > right)
		return (left);
	return (right);
}

/**
  * tree_top - Returns a new top node.
  * @node: Starting node.
  * @height: Height of heap.
  * @node_height: Height of starting node.
  *
  * Return: New top node.
  */
heap_t *tree_top(heap_t *node, int height, int node_height)
{
	heap_t *tmp;

	if (node_height >= height - 1)
	{
		if (node->right != NULL)
			return (node->right);
		return (node->left);
	}
	tmp = tree_top(node->right, height, node_height + 1);
	if (tmp != NULL)
		return (tmp);
	return (tree_top(node->left, height, node_height + 1));
}
