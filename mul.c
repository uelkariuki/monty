#include "monty.h"

/**
 * mul- The opcode mul multiplies the second top element of 
 * the stack with the top element of the stack
 * @stack: the pointer to the pointer of top of the stack
 * @line_number: the line number of opcode in the file
 */

void mul(stack_t **stack, unsigned int line_number)
{
                stack_t *top_of_stck = *stack;

                if (top_of_stck == NULL || top_of_stck->next == NULL)
                {
                        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                        exit(EXIT_FAILURE);
                }

                top_of_stck->next->n = top_of_stck->next->n * top_of_stck->n;

                pop(stack, line_number);
}
