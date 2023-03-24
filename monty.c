#include"monty.h"

global_t glob;

/**
* init_global_vars - initialise global vars
* @fp: file pointer
*
* Description: initialises some fields of global_t
*/

void init_global_vars(FILE *fp)
{
	glob.stack = 1;
	glob.head = NULL;
	glob.fp = fp;
	glob.line_num = 1;
}
/**
* main - Entry point
* @argc: # of CL args passed
* @argv: array of CL args passed
*
* Return: 0 if successful, anything else otherwise
*/

int main(int argc,  char **argv)
{
	FILE *fp;
	void (*op_func)(stack_t **stack, unsigned int line_number);
	char **args;
	int  check;
	size_t size;

	fp = check_file(argc, argv);
	init_global_vars(fp);
	args = malloc(sizeof(char *) * 2);
	if (!args)
	{
		fclose(fp);
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((check = _getline(&glob.buf, &size, fp)) != -1)
	{
		args[0] = strtok(glob.buf, "\n\t$ ");
		args[1] = strtok(NULL, "\n\t$ ");
		glob.arg = args[1];
		glob.args_arr = args;
		op_func = opc(args[0], glob.line_num);
		op_func(&glob.head, glob.line_num);
		glob.line_num++;
	}
	free_glob();
	return (0);
}
