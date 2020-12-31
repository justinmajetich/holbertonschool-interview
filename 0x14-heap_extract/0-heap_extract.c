#include "binary_trees.h"

/**
 * heap_extract - Extracts root node from a max binary heap.
 * @root: Double pointer to root node.
 * 
 * Return: Value stored in extracted node; or 0 on fail.
 */
int heap_extract(heap_t **root) {

    heap_t *old_root = *root;
    int root_value;

    if (*root == NULL) {
        return (0);
    } else {
        root_value = (*root)->n;
    }

    /* Check if left/right nodes exist */
    if ((*root)->left && ((*root)->right)) {

        /* Compare values of left and right nodes to find greater value.*/
        if (((*root)->left->n) > (((*root)->right->n))) {
            *root = (*root)->left;
        } else {
            *root = (*root)->right;
        }
    } else if ((*root)->left) {
        *root = (*root)->left;
    } else if ((*root)->right) {
        *root = (*root)->right;
    } else {
        *root = NULL;
    }

    /* Free root node. */
    free(old_root);

    root = NULL;
    return (root_value);
}
