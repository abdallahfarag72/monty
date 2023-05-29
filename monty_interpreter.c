#include "monty.h"

/**
 * process_line - Process a single line of Monty byte code
 * @line: The line to process
 * @line_number: The line number being executed
 * @stack: Double pointer to the top of the stack
 * @opcode_list: The list of opcode definitions
 */
void process_line(char *line, unsigned int line_number, stack_t **stack,
		instruction_t *opcode_list)
{
	/* Tokenize the line */
	char *opcode;
	int i;

	opcode = strtok(line, " ");
	if (opcode == NULL || opcode[0] == '#')
		return; /* Empty line or comment, skip */


	if (strcmp(opcode, "push") == 0)
	{
		data.arg_value = strtok(NULL, " "); /* Extract argument value */
		/* Handle the case when argument value is not present */
		if (data.arg_value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	/* Find the opcode function in the opcode list */
	i = 0;
	while (opcode_list[i].opcode != NULL)
	{
		if (strcmp(opcode, opcode_list[i].opcode) == 0)
		{
			opcode_list[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * read_file - Read and process a Monty byte code file
 * @file_path: Path to the Monty byte code file
 * @stack: Double pointer to the top of the stack
 * @opcode_list: The list of opcode definitions
 */
void read_file(char *file_path, stack_t **stack, instruction_t *opcode_list)
{
	FILE *file;
	char line[256];
	unsigned int line_number;
	size_t len;

	line_number = 0;
	file = fopen(file_path, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		process_line(line, line_number, stack, opcode_list);
	}

	fclose(file);
}

/**
 * free_stack - Frees the memory allocated for the stack
 * @stack: Double pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current;
	stack_t *next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}

/**
 * monty_interpreter - Monty byte code interpreter
 * @file_path: Path to the Monty byte code file
 */
void monty_interpreter(char *file_path)
{
	stack_t *stack;
	instruction_t opcode_list[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"nop", opcode_nop},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{NULL, NULL} /* Terminate the list with NULL */
	};

	stack = NULL;
	read_file(file_path, &stack, opcode_list);

	free_stack(&stack);
}
