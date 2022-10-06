#include "monty.h"

/**
* add - Adds the top two elements of the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void add(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;
	int sum = 0;

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	sum += temp->prev->n;
	sum += temp->n;
	temp->prev->n = sum;
	temp->prev->next = NULL;
	free(temp);
}

/**
* nop - No operation, do nothing
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void nop(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;

	;
}

/**
* sub - Pops top and subtracts value from new top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void sub(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->n -= temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
* div_s - Pops top and divides value into new top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void div_s(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	temp->prev->n /= temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
* mul - Pops top and multiplies value with new top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void mul(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->n *= temp->n;
	temp->prev->next = NULL;
	free(temp);
}
