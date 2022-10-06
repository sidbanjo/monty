#include "monty.h"
/**
 * _push - opcode that pushes an element to the stack.
 * @stack: stack where all our elements will be.
 * @line_number: numbers within the stack.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	char *str = NULL;

	str = strtok(NULL, "\t\n ");
	if (!str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(str);
	new->prev = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		new->next = NULL;
		*stack = new;
	}
}
/**
 * _pall - prints all the values , starting from the top of the stack.
 * @stack: stack where all our elements will be.
 * @line_number: numbers within the stack.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;
	if (!head)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: stack where all our elements will be.
 * @line_number: numbers within the stack.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
