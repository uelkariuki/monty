#include "monty.h"

#define STACK_FORMAT 0
#define QUEUE_FORMAT 1

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
	int line_number = 1, format = STACK_FORMAT;
	char *opcode, *args, *end_ln;
	long elem_value;

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
	while (fgets(the_instruction, MAX_LEN_INSTRUCTION, file_pointer) != NULL)
	{
		opcode = strtok(the_instruction, " \t\n");
		args = strtok(NULL, " \t\n");

		if  (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (args == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free_the_stack(&stack);
					exit(EXIT_FAILURE);
				}
				elem_value = strtol(args, &end_ln, 10);
				if (*end_ln != '\0')
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				push_func(&stack, (int)elem_value, format, argc, line_number);
			}

			else if (strcmp(opcode, "stack") == 0)
			{
				format = STACK_FORMAT;

			}
			else if (strcmp(opcode, "queue") == 0)
			{
				format = QUEUE_FORMAT;
			}
			else if (strcmp(opcode, "pall") == 0)
				pall_func(&stack);
			else if (strcmp(opcode, "pint") == 0)
				pint(&stack, line_number);
			else if (strcmp(opcode, "nop") == 0)
				nop();
			else if (strcmp(opcode, "pop") == 0)
				pop(&stack, line_number);
			else if (strcmp(opcode, "swap") == 0)
				swap(&stack, line_number);
			else if (strcmp(opcode, "add") == 0)
				add(&stack, line_number);
			else if (strcmp(opcode, "sub") == 0)
				sub(&stack, line_number);
			else if (strcmp(opcode, "div") == 0)
				div_func(&stack, line_number);
			else if (strcmp(opcode, "mul") == 0)
				mul(&stack, line_number);
			else if (strcmp(opcode, "mod") == 0)
				mod(&stack, line_number);
			else if (strcmp(opcode, "pchar") == 0)
				pchar(&stack, line_number);
			else if (strcmp(opcode, "pstr") == 0)
				pstr(&stack);
			else if (strcmp(opcode, "rotl") == 0)
				rotl(&stack);
			else if (strcmp(opcode, "rotr") == 0)
				rotr(&stack);

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
	free_the_stack(&stack);
	return (0);
}
/**
 * push_func - opcode function that pushes an element to the stack.
 * @stack: pointer to a pointer to a stack
 * @elem_value: the value of the element in the stack
 * @format: the format (mode) to be switched to, that is
 * between the stack format and the queue format
 * @argc: the number of command line arguments
 * @line_number:line number in the file
 */

void push_func(stack_t **stack, int elem_value, int format,
		int argc, int line_number)
{
	stack_t *new_stack_elem, *rear_elem;

	if (argc <= 0)
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
	new_stack_elem->next = NULL;

	if (format == STACK_FORMAT)
	{
		if (*stack != NULL)
		{
			new_stack_elem->next = *stack;
			(*stack)->prev = new_stack_elem;
		}
		*stack = new_stack_elem;
	}
	else if (format == QUEUE_FORMAT)
	{
		if (*stack == NULL)
		{
			*stack = new_stack_elem;
		}
		else
		{
			rear_elem = *stack;
			while (rear_elem->next != NULL)
			{
				rear_elem = rear_elem->next;
			}
			rear_elem->next = new_stack_elem;
			new_stack_elem->prev = rear_elem;
		}
	}
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
 * @line_number: line number of opcode in the file
 */

void pint(stack_t **stack, unsigned int line_number)
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
 */

void nop(void)
{

}
