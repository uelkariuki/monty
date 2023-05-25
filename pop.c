#include "monty.h"

/**
 * pop- The opcode pop removes the top element of the stack.
 * @stack: pointet to a pointer to the top of stack
 * @line_number: the line numebr of a file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node_stack;
	char *args;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	args = strtok(NULL, " \t\n");
	if (args != NULL)
	{
		fprintf(stderr, "L%d: usage: pop\n", line_number);
		exit(EXIT_FAILURE);
	}
	top_node_stack = *stack;

	if (top_node_stack->next != NULL)
	{
		/* 7 <-> 6 <-> 5 <-> 3 */
		/*top_node (7) next is (6), prev of (6) is (7) which*/
		/* is set to NULL thus removing it*/
		top_node_stack->next->prev = NULL;
	}
	*stack = top_node_stack->next;
}
