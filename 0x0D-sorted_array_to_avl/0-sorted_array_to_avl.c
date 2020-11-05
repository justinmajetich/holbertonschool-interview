#include "binary_trees.h"

/**
 * avl_tree_node - Function creates an AVL tree node
 * @parent: pointer to the parent node
 * @value: value to put into new node
 * Description: 0. New node
 * Return: see below
 * 1. upon success, return pointer to new node
 * 2. upon fail, return NULL
 */
avl_t *avl_tree_node(avl_t *parent, int value)
{
	/* Declare pointer to new node and pointer for insertion */
	avl_t *new_node = NULL;

	/* Allocate memory for new node but if fail, return NULL */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	/* Assign values or NULL  to new node */
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	if (parent != NULL)
	{
		if (new_node->n > parent->n)
			parent->right = new_node;
		else
			parent->left = new_node;
	}

	return (new_node);
}

/**
 * avl_generate - Generate an AVL tree using recursion.
 * @array: The sorted array from which to generate tree.
 * @left: The left-most index of subarray.
 * @right: The right-most index of subarray.
 * @parent: The parent of new node.
 */
void avl_generate(int *array, size_t left, size_t right, avl_t *parent)
{
	int mid;
	size_t size;
	avl_t *new_node = NULL;

	size = (right + 1) - left;
	mid = left + ((size / 2) - 1);

	if (left < right)
	{
		new_node = avl_tree_node(parent, array[mid]);

		avl_generate(array, left, mid, new_node);
		avl_generate(array, mid + 1, right, new_node);
	}
}

/**
 * sorted_array_to_avl - Generate an AVL tree from a sorted array.
 * @array: Array from which to generate tree.
 * @size: Size of array.
 *
 * Return: Pointer to root node of AVL tree; NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int mid;
	avl_t *root = NULL;

	if (size == 0)
		return (NULL);

	/* Get middle index of array. */
	if (size % 2 == 0)
		mid = (size / 2) - 1;
	else
		mid = size / 2;

	/* Create root node from middle array value. */
	root = avl_tree_node(NULL, array[mid]);

	avl_generate(array, 0, mid, root);
	avl_generate(array, mid + 1, size, root);

	return (root);
}
