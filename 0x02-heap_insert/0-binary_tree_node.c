#include "binary_trees.h"

/**
 * binary_tree_node - creates a new binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Value to attach to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = NULL;

    /* Allocate and assign space for new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
    {
        return (NULL);
    }

    /* Initialize members of new node */
    new_node->parent = parent;
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
