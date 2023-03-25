#include "monty.h"

/**
* pop - removes top element of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: removes and frees top element
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
}
