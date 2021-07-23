#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * count_nodes - count nodes
 * @root: double pointer
 *
 * Return: number of nodes
 */
int count_nodes(heap_t *root)
{
	int n;

	if (root == NULL)
		return (0);
	if (root)
		n = 1;
	n += count_nodes(root->left);
	n += count_nodes(root->right);

	return (n);
}

/**
 * tree_confirm - function that checks tree
 * @tree: pointer to the root
 * Return: 1 or 0 based on result
 */

int tree_confirm(const heap_t *tree)
{
	int p1, p2;

	if (tree == NULL)
		return (0);
	p1 = count_nodes(tree->left);
	p2 = count_nodes(tree->right);
	if (p1 == p2)
		return (1);
	return (0);
}

/**
 * parent - find the parent node
 * @root: double pointer
 *
 * Return: a pointer to the parent node
 */
heap_t *parent(heap_t *root)
{
	heap_t *p;
	int l, r, lf, rf;

	if (root == NULL)
		return (NULL);

	p = root;
	l = count_nodes(p->left);
	r = count_nodes(p->right);
	lf = tree_confirm(p->left);
	rf = tree_confirm(p->right);

	if (!l || !r)
		return (p);
	if (!lf || (lf && rf && l == r))
		return (parent(p->left));
	else if (!rf || (lf && rf && l > r))
		return (parent(p->right));
	return (p);
}

/**
 * sort - Sorts the parent and child nodes
 * @new: The new node to be inserted
 *
 * Return: nothing
 */
void sort(heap_t **new)
{
	heap_t *current;
	int aux;

	current = *new;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			aux = current->parent->n;
			current->parent->n = current->n;
			current->n = aux;
			*new = current->parent;
		}
		current = current->parent;
	}
}
/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: a pointer to the new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *p;

	p = parent(*root);
	new = binary_tree_node(p, value);
	if (new == NULL)
		return (NULL);
	if (p == NULL)
		*root = new;
	else if (!(p->left))
		p->left = new;
	else
		p->right = new;
	sort(&new);
	return (new);
}
