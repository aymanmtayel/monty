#ifndef M_H
#define M_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @operation: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *operation;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void _error(int error_n, ...);
void _error2(int error_n, ...);
void _open(char *file);
void _read(FILE *);
void func_id(char *, char *, int, int);
void func_id2(op_func oper, char *opers, char *value, int line, int type);
stack_t *new_node(int n);
int _token(char *buff, int line, int type);
void free_all(void);
void stack_add(stack_t **node, __attribute__((unused))unsigned int line);
void pstack(stack_t **stack, unsigned int line);
void top_pop(stack_t **stack, unsigned int line);
void top_print(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void _queue(stack_t **node, __attribute__((unused))unsigned int line);


#endif
