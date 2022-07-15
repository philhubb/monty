#include "monty.h"

/**
 * verif - verif
 * @numero: number
 * Return: always 0
 */
int verif(char *numero)
{
	int ojo = 0;

	if (!numero)
		return (1);

	if (numero[ojo] == 45)
		ojo++;
	while (numero[ojo])
	{
		if (numero[ojo] < 48 || numero[ojo] > 57)
			return (-1);
		ojo++;
	}
	return (0);
}

/**
 * nop - nop
 * @stack: node head
 * @num_linea: number of the line
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int num_linea)
{
	if (*stack)
	{};
	if (num_linea)
	{};
}

/**
 * sub - sub
 * @stack: node head
 * @num_linea: number of the line
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;
	stack_t *ojo2;
	int resta = 0;

	if (*stack && (*stack)->next)
	{
		ojo2 = (*stack)->next;
		resta = ojo2->n - (*stack)->n;
		ojo = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ojo);
		(*stack)->n = resta;
	}
	else
	{
		dprintf(2, "L%u: can't sub, stack too short\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * divi - divi
 * @stack: node head
 * @num_linea: number of the line
 * Return: nothing
 */
void divi(stack_t **stack, unsigned int num_linea)
{
	stack_t *ojo;
	stack_t *ojo2;
	int div = 0;

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
		div = ojo2->n / (*stack)->n;
		ojo = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ojo);
		(*stack)->n = div;
	}
	else
	{
		dprintf(2, "L%u: can't div, stack too short\n", num_linea);
		free(hola.linea);
		fclose(hola.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * free_l - free
 * @stack: node head
 * Return: nothing
 */
void free_l(stack_t **stack)
{
	stack_t *cleaner = *stack;

	while (*stack)
	{
		cleaner = cleaner->next;
		free(*stack);
		*stack = cleaner;
	}
}
