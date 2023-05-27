#include "monty.h"

/**
 * pstr- The opcode pstr prints the string starting at the
 * top of the stack, followed by a new line.
 * @stack: the pointer to the pointer of top of the stack
 */

void pstr(stack_t **stack)
{
	stack_t *top_of_stck = *stack;

	while (top_of_stck != NULL && top_of_stck->n != 0
			&& top_of_stck->n >= 0 && top_of_stck->n <= 127)
	{
		printf("%c", top_of_stck->n);
		top_of_stck = top_of_stck->next;
	}
	printf("\n");
}
