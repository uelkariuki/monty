#include "monty.h"
/**
 * run_opcode- helper function to running the respective opcode once called
 * @stack: a pointer to  a pointer to the top of the stack
 * @opcode: the opcode like pall, pop etc
 * @line_number: the line number of the opcode in the file
 */



void run_opcode(stack_t **stack, char *opcode, int line_number)
{
	if (strcmp(opcode, "pall") == 0)
		pall_func(stack);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop();
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		div_func(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack);
	else if (strcmp(opcode, "rotl") == 0)
		rotl(stack);
	else if (strcmp(opcode, "rotr") == 0)
		rotr(stack);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
		exit(EXIT_FAILURE);
	}

}
