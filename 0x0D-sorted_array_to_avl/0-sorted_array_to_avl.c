#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sorted_array_to_avl - Convert a sorted array to an AVL tree.
 *
 * @array - Array, aka tree fodder.
 * @size - Size of the array.
 *
 * Return: Pointer to the root node, or NULL.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node;
	int split;

	if (array == NULL)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	split = (size - 1) / 2;
	node->n = array[split];
	node->parent = NULL;
	node->left = build_a_branch(0, split - 1, array, node);
	node->right = build_a_branch(split + 1, size - 1, array, node);
	return (node);
}

/**
 * build_a_branch - Builds a tree branch
 *
 * @begin - Beginning of the branch
 * @end - End of the branch
 * @array - Tree fertilizer
 * @branch - Branch of the tree
 *
 * Return: Node
 */
avl_t *build_a_branch(int begin, int end, int *array, avl_t *branch)
{

	avl_t *node;
	int split;

	if (begin > end)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	split = (begin + end) / 2;
	node->n = array[split];
	node->parent = branch;
	node->left = build_a_branch(begin, split - 1, array, node);
	node->right = build_a_branch(split + 1, end, array, node);
	return (node);
}
