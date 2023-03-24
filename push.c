#include "monty.h"

/**
* pall - prints all the values on the stack
* @stack: pointer to stack_t pointer
* @line_number: current line in file
*
* Description: prints all values on the stack
* starting from the top
*/

void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *top;

	top = *stack;
	if (!top)
		return;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
/**
* push_stack - adds node at the beginning
* @stack: pointer to stack(or queue) pointer
* @n: interger to be added
*
* Description: follows LIFO with stack and FIFO with queue
*/

void push_stack(stack_t **stack, int n)
{
	stack_t *node, *top;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	top = *stack;
	node->n = n;
	node->prev = NULL;
	if (!top)
		node->next = NULL;
	else
		node->next = top;
	*stack = node;

}
/**
* push - pushes an element onto the stack
* @stack: address of stack_t pointer
* @line_number: an int
*
* Description: adds int onto stack
* Return: no return value
*/

void push(stack_t **stack, unsigned int line_number)
{
	int i, n;

	if (!glob.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	for (i = 0; glob.arg[i]; i++)
	{
		if (!isdigit(glob.arg[i]) && glob.arg[0] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_glob();
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(glob.arg);
	if (glob.stack == 1)
		push_stack(stack, n);
}
