#include "monty.h"

/**
 * rotl- The opcode rotl rotates the stack to the top,
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @stack: a pointer to the pointer of the top of stack
 */

void rotl(stack_t **stack)
{
	stack_t *top_elem, *temp_elem, *second_elem;

	if (*stack == NULL)
		return;

	top_elem = *stack;
	second_elem = top_elem->next;


	while (top_elem != NULL && top_elem->next != NULL)
	{
		temp_elem = second_elem;
		while (temp_elem->next != NULL)
		{
			temp_elem = temp_elem->next;
		}
		temp_elem->next = top_elem;
		*stack = second_elem;
		top_elem->next = NULL;
	}
}
