#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top_of_stack = *stack;
	int value;

	if (top_of_stack == NULL || top_of_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = top_of_stack->n;
	top_of_stack->n = top_of_stack->next->n;
	top_of_stack->next->n = value;
}
