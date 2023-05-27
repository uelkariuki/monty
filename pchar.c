#include "monty.h"

/**
 * pchar- The opcode pchar prints the char at the top of the stack,
 * followed by a new line.
 * @stack: the pointer to the pointer of top of the stack
 * @line_number: the line number of opcode in the file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top_of_stck = *stack;

	if (top_of_stck == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top_of_stck->n < 0 || top_of_stck->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top_of_stck->n);
}
