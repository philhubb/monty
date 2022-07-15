#ifndef STACK
#define STACK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
typedef struct globales
{
	int numero;
	int flag;
	char *linea;
	char *token;
	char *opco;
	FILE *fil;
} g_t;

extern g_t hola;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _mod(stack_t **stack, unsigned int num_linea);
void pchar(stack_t **stack, unsigned int num_linea);
void rotr(stack_t **stack, unsigned int num_linea);
void rotl(stack_t **stack, unsigned int num_linea);
void stack(stack_t **stack, unsigned int num_linea);
void queue(stack_t **stack, unsigned int num_linea);
void pstr(stack_t **stack, unsigned int num_linea);
void _mul(stack_t **stack, unsigned int num_linea);
void ver2(stack_t **stack, unsigned int x);
void err(stack_t **stack, unsigned int x);
void free_l(stack_t **stack);
void divi(stack_t **stack, unsigned int num_linea);
void sub(stack_t **stack, unsigned int num_linea);
void nop(stack_t **stack, unsigned int num_linea);
int verif(char *numero);
int tamanio(char *linea);
char quitarsalto(char *linea);
void swap(stack_t **stack, __attribute__((unused)) unsigned int num_linea);
void add(stack_t **stack, __attribute__((unused)) unsigned int num_linea);
void pint(stack_t **stack, unsigned int num_linea);
void pop(stack_t **stack, unsigned int num_linea);
void (*func(char *tokens))(stack_t **stack, unsigned int num_linea);
int main(__attribute__((unused)) int argc, char **argv);
void pall(stack_t **stack, unsigned int num_linea);
void push(stack_t **stack, unsigned int num_linea);

#endif
