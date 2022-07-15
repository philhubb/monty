#include "monty.h"

/**
 * err - err function
 * @stack: heade
 * @x: integer
 * Return: nothing
 */
void err(stack_t **stack, unsigned int x)
{
	dprintf(2, "L%u: unknown instruction %s\n", x, hola.linea);
	free(hola.linea);
	fclose(hola.fil);
	free_l(stack);
	if (stack)
	{
	}
	exit(EXIT_FAILURE);
}

/**
 * ver2 - ver2 function
 * @stack: heade
 * @contador: integer
 * Return: nothing
 */
void ver2(stack_t **stack, unsigned int contador)
{
	if (verif(hola.token) == 0)
		hola.numero = atoi(hola.token);
	else
	{
		dprintf(2, "L%u: usage: push integer\n", contador);
		free_l(stack);
		free(hola.linea);
		fclose(hola.fil);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mul - _mul function
 * @stack: heade
 * @num_linea: integer
 * Return: nothing
 */

void _mul(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;
	stack_t *ojo2;
	int mul = 0;

	if (*stack && (*stack)->next)
	{
		ojo2 = (*stack)->next;
		mul = ojo2->n * (*stack)->n;
		ojo = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ojo);
		(*stack)->n = mul;
	}
	else
	{
		dprintf(2, "L%u: can't mul, stack too short\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * _mod - _mod function
 * @stack: heade
 * @num_linea: integer
 * Return: nothing
 */

void _mod(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;
	stack_t *ojo2;
	int mul = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", num_linea);
			free(hola.linea);
			fclose(hola.fil);
			free_l(stack);
			exit(EXIT_FAILURE);
		}
		ojo2 = (*stack)->next;
		mul = ojo2->n % (*stack)->n;
		ojo = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ojo);
		(*stack)->n = mul;
	}
	else
	{
		dprintf(2, "L%d: can't mod, stack too short\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * pchar - pchar function
 * @stack: heade
 * @num_linea: integer
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;

	ojo = *stack;
	if (ojo == NULL)
	{
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		dprintf(2, "L%u: can't pchar, stack empty\n", num_linea);
		exit(EXIT_FAILURE);
	}
	if (ojo->n >= 128 || ojo->n < 0)
	{
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		dprintf(2, "L%d: can't pchar, value out of range\n", num_linea);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ojo->n);
}
