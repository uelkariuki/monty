#include "monty.h"

/**
 * mod- The opcode mod computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: the pointer to the pointer of top of the stack
 * @line_number: the line number of opcode in the file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top_of_stck = *stack;

	if (top_of_stck == NULL || top_of_stck->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top_of_stck->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_of_stck->next->n = top_of_stck->next->n % top_of_stck->n;
	pop(stack, line_number);
}
