#include "monty.h"

/**
 * stack_add - add a node to the stack
 * @node: pointer to the new node
 * @line: line number
 */

void stack_add(stack_t **node, __attribute__((unused))unsigned int line)
{
	stack_t *curr;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	curr = head;
	head = *node;
	head->next = curr;
	curr->prev = head;
}

/**
 * pstack - prints a whole stack
 * @stack: pointer to the stack to pe printed
 * @line: line number
 */

void pstack(stack_t **stack, unsigned int line)
{
	stack_t *curr;

	(void) line;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * top_pop - removes a node from the top of a stack.
 * @stack: pointer to the stack.
 * @line: line number.
 */

void top_pop(stack_t **stack, unsigned int line)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
		_error(7, line);
	curr = *stack;
	*stack = curr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(curr);
}

/**
 * top_print - prints the node of a stack.
 * @stack: pinter to the stack.
 * @line: line number.
 */

void top_print(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
		_error(6, line);
	printf("%d\n", (*stack)->n);
}

/**
 * nop - doesn’t do anything.
 * @stack: pointer to the stack
 * @line: line number
 */

void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
