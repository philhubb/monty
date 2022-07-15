#include "monty.h"

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 *
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;

	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.qs_len = 0;
}

/**
 * fs_close - close file stream on exit
 * @status: status passed to exit
 * @arg: pointer to file stream
 *
 * Return: void
 */
void fs_close(int status, void *arg)
{
	FILE *fs;

	(void)status;
	fs = (FILE *) arg;
	fclose(fs);
}

/**
 * free_line - free line returned by getline
 * @status: exit status
 * @arg: pointer to line
 *
 * Return: void
 */
void free_line(int status, void *arg)
{
	char **line = arg;

	(void)status;

	if (*line != NULL)
		free(*line);
}
