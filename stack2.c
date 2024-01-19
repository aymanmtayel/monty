#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: pointer to the top of the stack array
 * @line: line number inside the file for (errors)
 */

void _add(stack_t **stack, unsigned int line)
{
	int total;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error2(8, line, "add");

	(*stack) = (*stack)->next;
	total = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total;

	free((*stack)->prev);
	(*stack)->prev = NULL;
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

/**
 * _sub - subtracts the top two elements of the stack.
 * @stack: pointer to the top of the stack array
 * @line: line number inside the file for (errors)
 */

void _sub(stack_t **stack, unsigned int line)
{
        int diff;

        if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
                _error2(8, line, "sub");

        (*stack) = (*stack)->next;
        diff = (*stack)->n - (*stack)->prev->n;
        (*stack)->n = diff;

        free((*stack)->prev);
        (*stack)->prev = NULL;
}

