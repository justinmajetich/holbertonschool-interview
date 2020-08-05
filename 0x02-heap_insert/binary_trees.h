#ifndef BINARY_TREES
#define BINARY_TREES

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * struct my_stack_t - stack node
 *
 * @turn_direction: Traversal direction (0 = left, 1 = right)
 * @next: Pointer to next node in stack
 */
typedef struct my_stack_t
{
	int turn_direction;
	struct my_stack_t *next;
} my_stack_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const binary_tree_t *);

#endif
