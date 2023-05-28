#include "monty.h"
MontyData data = {0};

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char *file_path;

	file_path = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	monty_interpreter(file_path);

	return (EXIT_SUCCESS);
}
