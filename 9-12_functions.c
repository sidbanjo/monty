#include "monty.h"

/**
* mod - Pops top and divides value with new top, updates to remainder
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void mod(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (!temp || temp->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", linenumber);
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
	temp->prev->n %= temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
* pchar - Prints ascii value of top node in the stack
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pchar(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->n < 0 || temp->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", linenumber);
		cleanup();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
* pstr - Prints ascii value of values, starting from top
* @stack: Head of stack
* @linenumber: Line number of monty file
*/

void pstr(stack_t **stack, unsigned int linenumber)
{
	stack_t *temp = *stack;

	(void)linenumber;
	if (temp == NULL)
	{
		printf("\n");
		cleanup();
		exit(EXIT_FAILURE);
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			printf("\n");
			cleanup();
			exit(EXIT_SUCCESS);
		}
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}
