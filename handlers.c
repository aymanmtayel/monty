#include "monty.h"

/**
 * _open - open a file using name and read it,
 * if fail call the correct error code
 * @name: the file name
 * Return: void
 */

void _open(char *name)
{
	FILE *file = fopen(name, "r");

	if (name == NULL || file == NULL)
		_error(2, name);

	_read(file);
	fclose(file);
}

/**
 * _read - read a file
 * @file: pointer to the file name
 * Return: Void
 */

void _read(FILE *file)
{
	int line, type = 0;
	char *buff = NULL;
	size_t len = 0;

	for (line = 1; getline(&buff, &len, file) != -1; line++)
	{
		type = _token(buff, line, type);
	}
	free(buff);
}

/**
 * _token - tokenizes each line to determine which function to call
 * @buff: the line to tokenized
 * @line: the line number
 * @type: type of nodes (stack or queue)
 * Return: 0 if queue, 1 is stack
 */

int _token(char *buff, int line, int type)
{
	char *operation, *value;
	const char *delim = "\n ";

	if (buff == NULL)
		_error(4);

	operation = strtok(buff, delim);
	if (operation == NULL)
		return (type);
	value = strtok(NULL, delim);

	if (strcmp(operation, "queue") == 0)
		return (1);
	if (strcmp(operation, "stack") == 0)
		return (0);

	func_id(operation, value, line, type);
	return (type);
}

/**
 * func_id - identify the correct function for the operation required
 * @operation: operation to be executed
 * @value: element to be added
 * @line: line number
 * @type:type of storing ( 1 queue, 0 stack)
 */
void func_id(char *operation, char *value, int line, int type)
{
	int counter;
	int key;

	instruction_t opers[] = {
		{"push", stack_add},
		{"pall", pstack},
		{"pint", top_print},
		{"pop", top_pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", nop},
		{"sub", _sub},
		{"div", _div},
		{NULL, NULL},
	};

	if (operation[0] == '#')
		return;

	for (key = 1, counter = 0; opers[counter].operation != NULL; counter++)
	{
		if (strcmp(operation, opers[counter].operation) == 0)
		{
			func_id2(opers[counter].f, operation, value, line, type);
			key = 0;
		}
	}
	if (key == 1)
		_error(3, line, operation);
}

/**
 * func_id2 - calls push or call the correct function
 * @oper: pointer to the function to be called
 * @opers: the name of the operation
 * @value: the elemnt to be added
 * @line: line number
 * @type: type of the store (1 queue, 0 for stack)
 */

void func_id2(op_func oper, char *opers, char *value, int line, int type)
{
	stack_t *node;
	int key;
	int counter;

	key = 1;
	if (strcmp(opers, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			key = -1;
		}
		if (value == NULL)
			_error(5, line);
		for (counter = 0; value[counter] != '\0'; counter++)
		{
			if (isdigit(value[counter]) == 0)
				_error(5, line);
		}
		node = new_node(atoi(value) * key);
		if (type == 1)
			_queue(&node, line);
		if (type == 0)
			oper(&node, line);
	}
	else
		oper(&head, line);
}
