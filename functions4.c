#include "monty.h"


/**
 * pstr - pstri function
 * @stack: head
 * @num_linea: num linea
 * Return Nothing
 */
void pstr(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (num_linea)
		while (ojo && ojo->n != 0 && ojo->n > 0 && ojo->n < 128)
		{
			printf("%c", ojo->n);
			ojo = ojo->next;
		}
	printf("\n");
}

/**
 * rotl - rotl function
 * @stack: head
 * @num_linea: num linea
 * Return Nothing
 */

void rotl(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo, *ojo2;

	if (*stack && (*stack)->next)
	{
		ojo = *stack;
		ojo2 = ojo;
		*stack = ojo->next;
		(*stack)->prev = NULL;
		if (num_linea)
			while (ojo2->next)
			{
				ojo2 = ojo2->next;
			}
		ojo2->next = ojo;
		ojo->prev = ojo2;
		ojo->next = NULL;
	}
}


/**
 * rotr - rotr function
 * @stack: head
 * @num_linea: num linea
 * Return Nothing
 */

void rotr(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo2;

	if (*stack && (*stack)->next)
	{
		ojo2 = *stack;
		if (num_linea)
			while (ojo2->next)
			{
				ojo2 = ojo2->next;
			}
		ojo2->next = *stack;
		ojo2->prev->next = NULL;
		ojo2->prev = NULL;
		*stack = ojo2;
	}
}

/**
 * queue - queue function
 * @stack: head
 * @num_linea: num linea
 * Return Nothing
 */

void queue(stack_t **stack, unsigned int num_linea)
{
	if (stack || num_linea)
		hola.flag = 0;
}

/**
 * stack - stack function
 * @stack: head
 * @num_linea: num linea
 * Return Nothing
 */

void stack(stack_t **stack, unsigned int num_linea)
{
	if (stack || num_linea)
		hola.flag = 1;
}
