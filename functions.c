#include "monty.h"

/**
 * swap - swap function
 * @stack: head node
 * @num_linea: number of line
 * Return: Void function
 */
void swap(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	if (*stack && (*stack)->next)
	{
		ojo = (*stack)->next;
		if (ojo == NULL)
		{
			exit(0);
		}
		(*stack)->next = ojo->next;
		(*stack)->prev = ojo;
		ojo->next = *stack;
		ojo->prev = NULL;
		*stack = ojo;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * add - add function
 * @stack: head
 * @num_linea: number of line
 * Return: void function
 */
void add(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;
	stack_t *ojo2;
	int suma = 0;

	if (*stack && (*stack)->next)
	{
		ojo2 = (*stack)->next;
		suma = (*stack)->n + ojo2->n;
		ojo = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ojo);
		(*stack)->n = suma;
	}
	else
	{
		dprintf(2, "L%d: can't add, stack too short\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * pint - pint function
 * @stack: head
 * @num_linea: num linea
 * Return: void function
 */
void pint(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (ojo == NULL)
	{
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		dprintf(2, "L%u: can't pint, stack empty\n", num_linea);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ojo->n);
}


/**
 * pall - pall function
 * @stack: head
 * @num_linea: num linea
 * Return: void function
 */
void pall(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (num_linea)
		while (ojo)
		{
			printf("%d\n", ojo->n);
			ojo = ojo->next;
		}
}


/**
 * push - push function
 * @stack: head
 * @num_linea: number of line
 * Return: Always 0 (Success)
 */
void push(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ver2(stack, num_linea);
	if (hola.token)
	{
		ojo = malloc(sizeof(stack_t));
		if (ojo == NULL)
		{
			fputs("Error: malloc failed\n", stderr);
			exit(EXIT_FAILURE);
		}
		ojo->n = hola.numero, ojo->next = NULL;
		ojo->prev = NULL;
		if (*stack)
		{
			if (hola.flag == 1)
			{
				ojo->next = *stack;
				(*stack)->prev = ojo;
				*stack = ojo;
			}
			else
			{
				while ((*stack)->next)
					*stack = (*stack)->next;
				(*stack)->next = ojo, ojo->prev = *stack;
				while ((*stack)->prev)
					*stack = (*stack)->prev;
			}
		}
		else
			*stack = ojo;
	}
	else
	{
		free(hola.linea), fclose(hola.fil);
		dprintf(2, "L%u: usage: push integer\n", num_linea);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}
