#include "monty.h"

/**
 * opcode_pall - Prints all values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty byte code file
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
