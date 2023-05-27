#include "monty.h"

/**
 * run_push- a helper function for the push opcode
 * @args: the numbers of arguments (ie push int, int is the argument),
 * this is as a result of tokenizing the string into tokens.
 * @line_number: the line number of the opcode in the file
 * @format: the format to be specified, that is between
 * the stack and the queue format
 * @argc: the number of command line arguments
 */

void run_push(char *args, int line_number, int format, int argc)
{
	long elem_value;
	char *end_ln;

	if (args == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_the_stack(&stack);
		exit(EXIT_FAILURE);
	}
	elem_value = strtol(args, &end_ln, 10);
	if (*end_ln != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push_func(&stack, (int)elem_value, format, argc, line_number);
}
