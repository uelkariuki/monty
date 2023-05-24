#include "monty.h"
#define MAX_LEN_INSTRUCTION 200

void push_func(stack_t **stack, int elem_value);
void pall_func(stack_t **stack);

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	FILE *file_pointer;
	char the_instruction[MAX_LEN_INSTRUCTION];
	int line_number = 1, elem_value;
	char *opcode, *args;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_pointer = fopen(argv[1], "r");
	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(the_instruction, MAX_LEN_INSTRUCTION, file_pointer) != NULL)
	{
		opcode = strtok(the_instruction, " \t\n");
		args = strtok(NULL, " \t\n");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (args == NULL)
				{
					fprintf(stderr, "L<%d>: usage: push integer", line_number);
					exit(EXIT_FAILURE);
				}
				elem_value = atoi(args);
				push_func(&stack,elem_value);
			}
			else if (strcmp(opcode, "pall") == 0)
			{
				pall_func(&stack);
			}
			else
			{
				fprintf(stderr, "L<%d>: unknown instruction <%s>",
						line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		line_number++;
	}
	fclose(file_pointer);
	return(0);
}

void push_func(stack_t **stack, int elem_value)
{
	stack_t *new_stack_elem;
	/*char *opcode,*args;*/
	/*char the_instruction[MAX_LEN_INSTRUCTION];*/
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

void pall_func(stack_t **stack)
{
	 stack_t *temp_current;
	if (stack == NULL)
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
