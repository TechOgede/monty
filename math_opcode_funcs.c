#include "monty.h"


/**
* mod - calc the remaineder of the division on the top two
* elements of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: det the remaineder of the division of
* the int values of the top two elements
* a new elemnt containg the sum replaces the operands
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *curr, *next;
	int r;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	next = curr->next;
	r = next->n % curr->n;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new_node->next = next->next;
	new_node->prev = NULL;
	new_node->n = r;
	free(curr);
	free(next);
	*stack = new_node;
}

/**
* mul - multiplies  the top two elements of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: multiplies the int values of the top two elements
* a new elemnt containg the sum replaces the operands
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *curr, *next;
	int prod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	next = curr->next;
	prod = next->n * curr->n;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new_node->next = next->next;
	new_node->prev = NULL;
	new_node->n = prod;
	free(curr);
	free(next);
	*stack = new_node;
}

/**
* divide - performs division on the top two elements of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: divides the int values of the top two elements
* a new elemnt containg the sum replaces the operands
*/

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *curr, *next;
	int q;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	next = curr->next;
	q = next->n / curr->n;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new_node->next = next->next;
	new_node->prev = NULL;
	new_node->n = q;
	free(curr);
	free(next);
	*stack = new_node;
}

/**
* sub - subtracts the top two elements of the stack
* @stack: address of stack_t pointer
* @line_number: current line in file
*
* Description: subtracts the int values of the top two elements
* a new elemnt containg the sum replaces the operands
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *curr, *next;
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	next = curr->next;
	diff = next->n - curr->n;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	new_node->next = next->next;
	new_node->prev = NULL;
	new_node->n = diff;
	free(curr);
	free(next);
	*stack = new_node;
}

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
