#include "monty.h"

/**
* add - adds the top two elements of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: adds the int values of the top two elements
* a new elemnt containg the sum replaces the operands
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *curr, *next;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	next = curr->next;
	sum = curr->n + next->n;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new_node->next = next->next;
	new_node->prev = NULL;
	new_node->n = sum;
	free(curr);
	free(next);
	*stack = new_node;
}
