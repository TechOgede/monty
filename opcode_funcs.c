#include "monty.h"

/**
* rotl - rotates stack
* @stack: address of stack_pointer
* @line_number: current line in file
*
* Description: causes the top elem to become
* the last one and the second top elem becomes the
* top
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr, *first;

	(void)line_number;

	first = ptr = *stack;
	if ((*stack)->next)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = first;
		first->prev = ptr;
		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
	}
}
/**
* pstr - prints the string in the stack
* @stack: address of stack_pointer
* @line_number: current line in file
*
* Description: prints the int field of
* each stack_t element in a stack stack as a char.
* starting from the top
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *stack;
	while (ptr)
	{
		if (ptr->n <= 0 || ptr->n > 127)
			return;
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

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
