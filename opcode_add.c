#include "monty.h"

/**
 * opcode_add - Add the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	opcode_pop(stack, line_number);  /* Remove the top element */
	(*stack)->n = sum;  /* Store the result in the second top element */
}
