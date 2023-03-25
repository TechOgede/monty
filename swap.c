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
