#include "monty.h"

/**
 * sub- The opcode sub subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: the pointer to the pointer of top of the stacki
 * @line_number: the line number of opcode in the file
 */

void sub(stack_t **stack, unsigned int line_number)
{
                stack_t *top_of_stck = *stack;

                if (top_of_stck == NULL || top_of_stck->next == NULL)
                {
                        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                        exit(EXIT_FAILURE);
                }

                top_of_stck->next->n = top_of_stck->next->n - top_of_stck->n;
                
		pop(stack, line_number);
}
