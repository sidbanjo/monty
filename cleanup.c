#include "monty.h"

/**
* cleanup - Free vars and close open file stream
*/

void cleanup(void)
{
	if (m.buff != NULL)
		free(m.buff);
	if (m.stack != NULL)
		free_dlistint(m.stack);
	if (m.margs != NULL)
		free(m.margs);
	if (m.file != NULL)
		fclose(m.file);
}
