#include "monty.h"

/**
 * free_the_stack- this function frees all memory allocated by malloc
 * @stack: the pointer to the pointer of top of the stack
 */
void free_the_stack(stack_t **stack)
{
	stack_t *temp, *current_node;

	if (*stack == NULL)
		return;
	current_node = *stack;

	while (current_node != NULL)
	{
		temp = current_node;
		current_node = current_node->next;
		free(temp);
	}
	*stack = NULL;
}
