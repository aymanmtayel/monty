#include "monty.h"

/**
 * _error - fuction to print the appropriate error message to stderr
 * @error_n: the internal error code to match the message
 */

void _error(int error_n, ...)
{
	va_list list;
	char *oper;
	int line;

	va_start(list, error_n);

	switch (error_n)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			oper = va_arg(list, char *);
			fprintf(stderr, "Error: Can't open file %s\n", oper);
			break;
		case 3:
			line = va_arg(list, int);
			oper = va_arg(list, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, oper);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			line = va_arg(list, int);
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		default:
			break;
	}
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * _error2 - complmentry function for errors
 * @error_n: the internal error code to match the message
 * Return: Void
 */

void _error2(int error_n, ...)
{
	va_list list;
	char *oper;
	int line, usline;

	va_start(list, error_n);

	switch (error_n)
	{
		case 6:
			line = va_arg(list, int);
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case 7:
			line = va_arg(list, int);
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case 8:
			usline = va_arg(list, unsigned int);
			oper = va_arg(list, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", usline, oper);
			break;
		case 9:
			usline = va_arg(list, unsigned int);
			fprintf(stderr, "L%d: division by zero\n", usline);
		default:
			break;
	}
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * _error3 - error function for printing strings and characters
 * @error_n: the internal error code to match the message
 * Return: void
 */

void _error3(int error_n, ...)
{
	va_list list;
	int line;

	va_start(list, error_n);
	line = va_arg(list, int);

	switch (error_n)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		default:
			break;
	}
	free_all();
	exit(EXIT_FAILURE);
}
