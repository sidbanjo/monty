nclude "monty.h"

/** global struct with important monty data */
monty m;

/**
* main - Main file of monty interpreter program
* @ac: Arg count
* @av: Arg array
* Return: Success or fail
*/

int main(int ac, char **av)
{
	m.file = NULL;
	m.linenumber = 1;
	m.margs = malloc(sizeof(char *) * 10);
	if (m.margs == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		cleanup();
		exit(EXIT_FAILURE);
	}
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		cleanup();
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK) == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		cleanup();
		exit(EXIT_FAILURE);
	}
	m.file = fopen(av[1], "r");
	if (m.file == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		cleanup();
		exit(EXIT_FAILURE);
	}
	montyparser();
	cleanup();
	return (EXIT_SUCCESS);
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms

