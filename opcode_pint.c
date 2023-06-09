#include "monty.h"

/**
 * opcode_pint - Print the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
