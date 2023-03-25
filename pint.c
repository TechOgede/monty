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
