#include "monty.h"
/**
 * op_func - Function
 * @buff: array
 * Return: void.
 */
void (*op_func(char *buff))(stack_t **stack, unsigned int line_number)
{
	int j = 0;
	instruction_t func[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"swap", _swap},
	{"add", _add},
	{"nop", _nop},
	{NULL, NULL}
	};

	while (func[j].opcode)
	{
		if (strcmp(func[j].opcode, buff) == 0)
			return (func[j].f);
	j++;
	}
	return (NULL);
}
