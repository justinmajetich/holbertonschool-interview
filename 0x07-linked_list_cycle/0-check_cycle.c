#include "lists.h"

int run_cycle_check(listint_t *slow, listint_t *fast);

/**
 * check_cycle - Determine if a linked list contains a cycle.
 * @list: List to inspect
 *
 * Return: 1 if list contains cycle; otherwise, 0.
 */
int check_cycle(listint_t *list)
{
	if (list)
		return (run_cycle_check(list, list->next));
	else
		return (0);
}

/**
 * run_cycle_check - Recursively run slow and fast nodes through list.
 * @slow: Slow node
 * @fast: Fast node
 *
 * Return: 1 if list contains cycle; otherwise, 0.
 */
int run_cycle_check(listint_t *slow, listint_t *fast)
{
	if (!slow || !fast || !fast->next)
		return (0);
	else if (fast == slow)
		return (1);
	else
		return (run_cycle_check(slow->next, fast->next->next));
}
