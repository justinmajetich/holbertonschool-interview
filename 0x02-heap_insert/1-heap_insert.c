#include "binary_trees.h"

size_t binary_tree_size(const heap_t *tree);
void position_inserted_node(heap_t *inserted);
void determine_insertion_path(size_t size, my_stack_t *new_node);
void insert_new_node(heap_t *root, heap_t *new_node, my_stack_t *directions);

/**
 * heap_insert - inserts node into a max binary heap
 * 
 * @root: Double pointer to root of heap
 * @value: Value to assign to inserted node
 * 
 * Return: Pointer to inserted node, or NULL on Fail
*/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = NULL;
    size_t tree_size = 0;
    my_stack_t *directions = NULL;

    /* If pointer to root is NULL, init root with new node */
    if (*root == NULL)
    {
        new_node = binary_tree_node(*root, value);
        *root = new_node;
        return (new_node);
    }

    /* Recurse to find parent for new leaf */
    /* First, determine size of tree */
    tree_size = binary_tree_size(*root);

    /* Second, find path to next available position */
    determine_insertion_path(tree_size + 1, directions);

    /* Create parentless new node for insertion */
    new_node = binary_tree_node(NULL, value);

    /* Insert new node at next available position in heap */
    insert_new_node(*root, new_node, directions);

    /* Bubble up to proper position */
    position_inserted_node(new_node);

    /* Check if new node is now root */
    if (new_node->parent == NULL)
    {
        *root = new_node;
    }

    /* Return pointer to inserted node */
    return (new_node);
}

/**
 * position_inserted_node - bubble-up inserted node to sorted position
 * @inserted: Newly inserted node
 */
void position_inserted_node(heap_t *inserted)
{
    heap_t *temp = NULL;

    /* If inserted node is greater than parent, swap positions */
    while ((inserted->parent != NULL) && (inserted->n > inserted->parent->n))
    {
        /* Assign parent's attributes to temp variable */
        temp->parent = inserted->parent->parent;
        temp->left = inserted->parent->left;
        temp->right = inserted->parent->right;

        inserted->parent->parent = inserted;
        inserted->parent->left = inserted->left;
        inserted->parent->right = inserted->right;

        inserted->parent = temp->parent;
        inserted->left = temp->left;
        inserted->right = temp->right;
    }
}

/**
 * insert_new_node - insert node at next available position
 * @root: Root of heap
 * @new_node: New node to insert
 * @directions: Turn by turn directions to next available position
 * 
 * Return: pointer to inserted node; NULL on Failure
 */
void insert_new_node(heap_t *root, heap_t *new_node, my_stack_t *directions)
{
    heap_t *runner = root;

    /* Navigate to next available position */
    while (directions->next != NULL)
    {
        /* Turn left on 0 */
        if (directions->turn_direction == 0)
        {
            runner = runner->left;
        }
        /* Turn right on 1 */
        else
        {
            runner = runner->right;
        }
        directions = directions->next;
    }
    
    /* Point parent to new node */
    if (directions->turn_direction == 0)
    {
        runner->left = new_node;
    }
    else
    {
        runner->right = new_node;
    }

    /* Point new node back to parent */
    new_node->parent = runner;   
}

/**
 * determine_insertion_path - determine sequence of turns to reach next available position
 * @size: Remaining size of tree
 * @new_node: Last node pushed to the stack
 */
void determine_insertion_path(size_t size, my_stack_t *new_node)
{
    size_t remainder, quotient = 0;

    if (size > 1)
    {
        remainder = size % 2;
        quotient = size / 2;

        /* Push new node onto stack */
        new_node = malloc(sizeof(my_stack_t));
        if (new_node != NULL)
        {
            new_node->turn_direction = remainder;
            new_node->next = NULL;
            
            determine_insertion_path(quotient, new_node->next);
        }
    }
}

/**
 * binary_tree_size - measure size of binary tree
 * @tree: tree to measure
 *
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
	return (0);
}
