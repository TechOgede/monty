#include "monty.h"

/**
* opc - checks the opcode read from the file
* @arg: argument to opcode
* @line: current line in file
*
* Description: checks the opcode from the file
* against the opcode in the instruction_t and
* returns the corresponding function.
* Return: a pointer to a function
*/

void (*opc(char *arg, size_t line))(stack_t **stack, unsigned int line_number)
{
	int inst_arr_len, i;

	instruction_t inst_arr[] = {
				  {"push", push},
				  {"pall", pall},
				 };
	inst_arr_len = sizeof(inst_arr) / sizeof(instruction_t);
	for (i = 0; i < inst_arr_len; i++)
	{
		if (strcmp(arg, inst_arr[i].opcode) == 0)
			return (inst_arr[i].f);
	}
	fprintf(stderr, "L%ld: unknown instruction %s\n", line, arg);
	free_glob();
	exit(EXIT_FAILURE);
}
