#include "monty.h"

/**
 * opcodes_handle- function to handle the opcodes
 * @opcode: the opcode to be handled
 * @line_number: the line number in a file
 */

void opcodes_handle(char *opcode)
{

	int line_number = 0;

	if (strcmp(opcode, "push") == 0)
		push_func(&stack);
	else if (strcmp(opcode, "pall") == 0)
		pall_func(&stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(&stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(&stack);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
		exit(EXIT_FAILURE);
	}

}

