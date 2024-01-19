#include "monty.h"
stack_t *head = NULL;

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments array of values
 * Return: error code if failure, 0 if succeed
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
		_error(1);
	_open(argv[1]);
	free_all();
	return (0);
}

/**
 * new_node - create a new node
 * @n: element to be added
 * Return: pointer to the node or error code
 */
stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_all - eleminate all memory leaks
 * Return: void
 */

void free_all(void)
{
	stack_t *curr;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}

/**
 * _queue - adds new node to a queue
 * @node: pointer to the node to be added
 * @line: the line number of the operation
 * Return: Void
 */

void _queue(stack_t **node, __attribute__((unused))unsigned int line)
{
	stack_t *curr;

	if (node == NULL || *node == NULL)
		_error(0);
	if (head == NULL)
	{
		head = *node;
		return;
	}
	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = *node;
	(*node)->prev = curr;
}
