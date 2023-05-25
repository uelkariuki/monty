#include "monty.h"

#define MAX_LEN_INSTRUCTION 200

stack_t *stack;
/**
 * main- main function
 * @argc: number of command line arguments
 * @argv: an array containing the program command line arguments
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	FILE *file_pointer = fopen(argv[1], "r");
	char the_instruction[MAX_LEN_INSTRUCTION];
	int line_number = 1;
	char *opcode;
	stack_t *temp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;

	while (fgets(the_instruction, MAX_LEN_INSTRUCTION, file_pointer) != NULL)
	{
		opcode = strtok(the_instruction, " \t\n");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
				push_func(&stack);
			else if (strcmp(opcode, "pall") == 0)
				pall_func(&stack);
			else if (strcmp(opcode, "pint") == 0)
				pint(&stack, line_number);
			else if (strcmp(opcode, "nop") == 0)
				nop(&stack);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file_pointer);
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
/**
 * push_func - opcode function that pushes an element to the stack.
 * @stack: pointer to a pointer to a stack
 * @line_number:line number in the file
 */

void push_func(stack_t **stack)
{
	stack_t *new_stack_elem;
	char *end_ln, *args;
	long elem_value;
	int line_number;

	args = strtok(NULL, " \t\n");
	line_number = atoi(args);

	if (args == NULL || line_number == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	elem_value = strtol(args, &end_ln, 10);
	if (*end_ln != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack_elem = (stack_t *)malloc(sizeof(stack_t));

	/* failed memory allocation*/
	if (new_stack_elem == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack_elem->n = elem_value;
	new_stack_elem->prev = NULL;
	new_stack_elem->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_stack_elem;
	}
	*stack = new_stack_elem;
}

/**
 * pall_func- opcode function that prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: pointer to a pointer to a stack
 */

void pall_func(stack_t **stack)
{
	stack_t *temp_current;

	if (*stack == NULL)
	{
		return;

	}

	temp_current = *stack;
	while (temp_current != NULL)
	{
		printf("%d\n", temp_current->n);
		temp_current = temp_current->next;
	}
}

/**
 * pint- The opcode pint prints the value at the top of the
 * stack, followed by a new line.
 * @stack: pointer to a pointer to the stack
 */

void pint(stack_t **stack, int line_number)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}



}

/**
 * nop- The opcode nop doesn’t do anything.
 * @stack: pointer to a pointer to the stack
 */

void nop(stack_t **stack __attribute__((unused)))
{

}
