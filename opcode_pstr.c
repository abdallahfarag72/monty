#include "monty.h"

/**
 * opcode_pstr - Print the string starting at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number being executed
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	(void)line_number;
	while (current != NULL && current->n != 0
		&& current->n >= 0 && current->n <= 127)
	{
		int value;

		value = current->n;
		printf("%c", value);

		current = current->next;
	}

	printf("\n");
}
