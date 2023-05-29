#include "monty.h"

/**
 * opcode_div - Divides the second top element by the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number in the Monty file
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n /= top->n;
	opcode_pop(stack, line_number);
}
