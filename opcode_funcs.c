#include "monty.h"

/**
* pchar - prints the char at the top of the stack
* @stack: address of stack_pointer
* @line_number: current line in file
*
* Description: prints the int field of stack_t
* as a char
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

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
