#include "monty.h"


/**
* queue_f - sets data format to FIFO
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: sets the globa var, glob.stack to 0
*/

void queue_f(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	glob.stack = 0;
}

/**
* stack_f - sets data format to LIFO
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: sets the globa var, glob.stack to 1
*/

void stack_f(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	glob.stack = 1;
}

/**
* nop - does nothing
* @stack: addresss of stack_t pointer
* @line_number: current line in file
*
* Description: simply does nothing
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

#include "monty.h"

/**
* pint - prints the value at the top of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: prints topmost value in stack
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

#include "monty.h"

/**
* swap - swaps the two top elements in the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: swaps the two top elements in the stack
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *next;

	if (*stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	next = curr->next;
	curr->next = next->next;
	curr->prev = next;
	next->next = curr;
	next->prev = NULL;
	*stack = next;
}
