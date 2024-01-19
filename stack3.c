#include "monty.h"
/**
 * _mod - computes the rest of division of the second
 * top element of the stack by the top element of the stack.
 *
 * @stack: pointer to the top of the stack array
 * @line: line number inside the file for (errors)
 */

void _mod(stack_t **stack, unsigned int line)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_error2(8, line, "mod");

	if ((*stack)->n == 0)
		_error2(9, line);

	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _pchar - prints the char crossponding to an ASCII value
 * at the top of the stack, followed by a new line.
 *
 *  @stack: pointer to the top of the stack array
 *  @line: line number inside the file for errors handling
 */

void _pchar(stack_t **stack, unsigned int line)
{
	int charr;

	if (stack == NULL || *stack == NULL)
		_error3(10, line);

	charr = (*stack)->n;
	if (charr < 0 || charr > 127)
		_error3(11, line);
	printf("%c\n", charr);
}

/**
 * _pstr - prints the string crossponding to an ASCII value
 * at the top of the stack, followed by a new line.
 *
 *  @stack: pointer to the top of the stack array
 *  @line: line number inside the file for errors handling (unused)
 */

void _pstr(stack_t **stack, __attribute__((unused))unsigned int line)
{
	int string;
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	curr = *stack;
	while (curr)
	{
		string = curr->n;
		if (string <= 0 || string > 127)
			break;

		printf("%c", string);
		curr = curr->next;
	}
	printf("\n");
}

