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
    return run_cycle_check(list->next, list->next->next);
}

int run_cycle_check(listint_t *slow, listint_t *fast)
{
    if (!slow || !fast)
        return (0);
    else if (fast == slow)
        return (1);
    else
        return run_cycle_check(slow->next, fast->next->next);
}