#include "monty.h"
char *value = NULL;
/**
 * free_list - free the list
 * @head: pointer to a stack_t
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * main - main function
 * @argc: int
 * @argv: array
 * Return: 0
*/
int main(int argc, char *argv[])
{
	char buffer[1024], *token = NULL;
	FILE *fp;
	int line_number = 0;
	void (*opcode_func)(stack_t **stack, unsigned int line_number);
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 1024, fp))
	{
		line_number++;
		token = strtok(buffer, "\n\t $");
		if (!token)
			continue;
		opcode_func = op_func(token);
		if (!opcode_func)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		opcode_func(&head, line_number);
	}
	free_list(head);
	fclose(fp);
	return (0);
}
