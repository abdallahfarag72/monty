#include "monty.h"

/**
 * push_stack - Pushes a new node with the given value to the top of the stack
 * @stack: Double pointer to the top of the stack
 * @value: Value to be pushed onto the stack
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * is_numeric - Check if a string represents a numeric value
 * @str: The string to check
 *
 * Return: 1 if the string is numeric, 0 otherwise
 */
int is_numeric(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}

/**
 * opcode_push - Pushes an element to the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number in the Monty byte code file
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "Error: Stack not initialized\n");
		exit(EXIT_FAILURE);
	}

	if (data.arg_value == NULL || !is_numeric(data.arg_value))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(data.arg_value);
	push_stack(stack, value);
}
