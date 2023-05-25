#include "monty.h"

/**
 * pstr- The opcode pstr prints the string starting at the
 * top of the stack, followed by a new line.
 * @stack: the pointer to the pointer of top of the stack
 * @line_number: the line number of opcode in the file
 */

void pstr(stack_t **stack, unsigned int line_number)
{
                stack_t *top_of_stck = *stack;
		

		while (top_of_stck != NULL && top_of_stck->n != 0)
		{
			if (top_of_stck->n < 0 || top_of_stck->n > 127)
			{
				fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
				exit(EXIT_FAILURE);
			}
			printf("%c", top_of_stck->n);
			top_of_stck = top_of_stck->next;
		}
		printf("\n");
}
