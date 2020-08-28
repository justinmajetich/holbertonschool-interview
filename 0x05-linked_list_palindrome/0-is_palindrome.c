#include "lists.h"

int is_equal(listint_t **left, listint_t *right);

/**
 * is_palindrome - Detects if the contents of linked list are palindromic
 * @head: Head node of list
 *
 * Return: 0 if not a palindrome; 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
	/* If list is empty, consider it a palindrome */
	if (*head == NULL)
		return (1);

    /* Check if list is palindrome */
    return is_equal(head, *head);
}

/**
 * is_equal - Recursively check if symmetric nodes are of equal value
 * @left: Node probing from the left
 * @right: Node probing from the right
 *
 * Return: 1 if values match; otherwise, 0
 */
int is_equal(listint_t **left, listint_t *right)
{
	int is_palin = 0;

	/* Base case is end of list */
	if (right == NULL)
		return (1);

	/* Check if nodes have equal value */
	if (!is_equal(left, right->next))
		return (0);

	/* Check is node pair is palindrome */
	is_palin = (right->n == (*left)->n);

    /* Move left pointer forward */
	*left = (*left)->next;

	return is_palin;
}
