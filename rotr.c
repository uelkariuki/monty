#include "monty.h"

/**
 * rotr- The opcode rotl rotates the stack to the bottom
 * The last element of the stack becomes the top element of the stack
 * @stack: a pointer to the pointer of the top of stack
 */

void rotr(stack_t **stack)
{
        stack_t *top_elem = *stack, *bottom_elem = *stack; 

	if (top_elem == NULL || top_elem->next == NULL)
		return;

	while( bottom_elem->next != NULL)
	{
		bottom_elem = bottom_elem->next;
	}
	bottom_elem->prev->next= NULL;
	bottom_elem->prev = NULL;
	bottom_elem->next = top_elem;
	top_elem->prev = bottom_elem;
	*stack = bottom_elem;

}
