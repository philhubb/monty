#include "monty.h"

qs_t var;

/**
 * main - entry level - interpreter for Monty ByteCodes files
 * @argc: number of arguments passed
 * @argv: array of arguments(strings)
 * Return: EXIT_SUCCESS for success, EXIT_FAILURE for failure
 */

int main(int argc, char *argv[])
{
	char *line = NULL, *op = NULL;
	size_t n = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;

	var.q_or_s = 0;
	var.qs_len = 0;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_line, &line);
	on_exit(free_stack, &stack);
	on_exit(fs_close, fs);
	while (getline(&line, &n, fs) != -1)
	{
		line_number++;
		op = strtok(line, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			execute(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}

/**
 * execute - confirm and execute instruction
 * @op: instruction to check
 * @line_number: script line number
 * @stack: double pointer pointing to the stack's top
 * Return: void
 */

void execute(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; codes[i].opcode != NULL; i++)
	{
		if (strcmp(codes[i].opcode, op) == 0)
		{
			codes[i].f(stack, line_number);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}
