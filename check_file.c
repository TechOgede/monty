#include "monty.h"

/**
* check_file - checks the path passed as arg to monty
* @argc: int denoting number of args passed
* @argv: array of args passed
*
* Description: opens file and checks for errors
* Return: a pointer to file
*/

FILE *check_file(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
