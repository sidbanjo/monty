#include "monty.h"

/**
 * print_dlistint - prints a doubly linked lists
 * @h: dlistint_t head
 * Return: number of elements in dlistin_t
 */
size_t print_dlistint(const stack_t *h)
{
	const stack_t *temp;
	int count = 0;

	temp = h;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		count++;
		temp = temp->next;
	}
	return (count);
}

/**
 * add_dnodeint - add node at beginning of dlist
 * @head: head of dlist
 * @n: data of each node
 * Return: address of new element or NULL
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = (*head);
	new->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new;

	(*head) = new;

	return (new);
}

/**
 * add_dnodeint_end - add node to the end of a dlistint_t list
 * @head: beginning of dlistint_t
 * @n: data to insert into node
 * Return: address of the new element or NULL
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp;

	if (head == NULL || new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		cleanup();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		m.stack = new;
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
	return (new);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a specific index
 * @idx: index to insert at
 * @h: head of dlistint_t
 * @n: data for new node
 * Return: address to the new dnodeint or NULL on failure
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	unsigned int i;
	stack_t *new, *hold = *h;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;

	if (idx == 0)
	{
		new->next = *h;
		new->prev = NULL;

		if (*h)
			(*h)->prev = new;

		*h = new;
		return (new);
	}

	for (i = 0; hold; i++, hold = hold->next)
		if (i == idx - 1)
		{
			new->next = hold->next;
			if (new->next)
				new->next->prev = new;
			new->prev = hold;
			hold->next = new;
			return (new);
		}
	free(new);
	return (NULL);
}

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: Pointer to head of list
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp, *next;

	if (head == NULL)
	{
		return;
	}
	temp = next = head;
	while (next->next != NULL)
	{
		next = next->next;
		free(temp);
		temp = next;
	}
	free(temp);
}
