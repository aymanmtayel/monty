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
		_error2(7, line);
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
		_error2(6, line);
	printf("%d\n", (*stack)->n);
}

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: pointer to the stack array
 * @line: line number in the file
 */

void _swap(stack_t **stack, unsigned int line)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error2(8, line, "swap");
	curr = (*stack)->next;
	(*stack)->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = *stack;
	curr->next = *stack;
	(*stack)->prev = curr;
	curr->prev = NULL;
	*stack = curr;
}
