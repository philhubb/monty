#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.q_or_s = STACK;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the top of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.q_or_s = QUEUE;
}

/**
 * add_node - add a new node to a circular linked list
 * @stack: double pointer to the beginning of the circular linked list
 * @n: value to add to the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.q_or_s == STACK || var.qs_len == 0)
		*stack = new;
	return (new);
}
