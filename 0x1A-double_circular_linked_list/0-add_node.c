#include "list.h"
#include "string.h"

List *add_node(List **list, char *str);

/**
 * add_node_end - Add node to end of list.
 *
 * @list: A pointer to the head of the list to modify.
 * @str: The string content to add to new node.
 *
 * Return: Address of added node; NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	if (str == NULL)
		return (NULL);

	return (add_node(list, str));
}

/**
 * add_node_begin - Add node to beginning of list.
 *
 * @list: A pointer to the head of the list to modify.
 * @str: The string content to add to new node.
 *
 * Return: Address of added node; NULL on failure.
 */

List *add_node_begin(List **list, char *str)
{
	List *new = NULL;

	if (str == NULL)
		return (NULL);

	new = add_node(list, str);

	/* If node insert did not fail, make new node head of list */
	if (new != NULL)
		*list = new;

	return (new);
}

/**
 * add_node - Add node to beginning/end of list.
 *
 * @list: A pointer to the head of the list to modify.
 * @str: The string content to add to new node.
 *
 * Return: Address of added node; NULL on failure.
 */
List *add_node(List **list, char *str)
{
	List *head = NULL, *tail = NULL, *new = NULL;

	/* Set up new node. */
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->prev = NULL;
	new->next = NULL;

	/* If list is empty, start with new node. */
	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
	}
	else
	{
		head = *list;
		tail = (*list)->prev;

		/* Point current head to new node. */
		head->prev = new;

		/* Point current tail to new node. */
		tail->next = new;

		/* Point new node to surrounding nodes. */
		new->next = head;
		new->prev = tail;
	}

	return (new);
}
