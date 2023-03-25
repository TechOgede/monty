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
	glob.line_num = 0;
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
	int  check;
	size_t size;

	fp = check_file(argc, argv);
	init_global_vars(fp);
	glob.args_arr = malloc(sizeof(char *) * 2);
	if (!glob.args_arr)
	{
		fclose(fp);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while ((check = _getline(&glob.buf, &size, fp)) != -1)
	{
		glob.line_num++;
		if (_strlen(glob.buf) == 1)
			continue;
		glob.args_arr[0] = strtok(glob.buf, "\n\t$ ");
		glob.args_arr[1] = strtok(NULL, "\n\t$ ");
		if (glob.args_arr[0])
		{
			if (_strcmp(glob.args_arr[0], "#") == 0 || glob.args_arr[0][0] == '#')
				continue;
			glob.arg = glob.args_arr[1];
			op_func = opc(glob.args_arr[0], glob.line_num);
			op_func(&glob.head, glob.line_num);
		}
	}
	free_glob();
	return (0);
}
