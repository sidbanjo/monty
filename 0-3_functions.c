#include "monty.h"

/**
* push - Adds values to top of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void push(stack_t **stack, unsigned int linenumber)
{
	int a, i = 0;
	char *n = m.margs[1];

	if (!n)
	{
		dprintf(2, "L%d: usage: push integer\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (n[i])
	{
		if (((n[i] < '0' || n[i] > '9') && n[i] != '-')
		    || (n[i] == '-' &&  n[i + 1] == '\0'))
		{
			dprintf(2, "L%d: usage: push integer\n", linenumber);
			cleanup();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	a = atoi(m.margs[1]);
	add_dnodeint_end(stack, a);
}

/**
* pall - Prints all the values on the stack, starting from the top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pall(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	(void)linenumber;
	if (!temp)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}

/**
* pint - Prints the value at the top of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pint(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	printf("%d\n", temp->n);
}

/**
* pop - Removed the top element of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pop(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->prev != NULL)
		temp->prev->next = NULL;
	free(temp);
	if (temp->prev == NULL && temp->next == NULL)
		*stack = NULL;
}

/**
* swap - Swaps the values of the top two elements of stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void swap(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;
	int swap;

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	swap = temp->prev->n;
	temp->prev->n = temp->n;
	temp->n = swap;
}
