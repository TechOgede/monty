#include "monty.h"

/**
* free_glob - cleanup function
*
* Description: closes the file, frees allocated memory
*/

void free_glob(void)
{
	stack_t *temp;

	fclose(glob.fp);
	free(glob.buf);
	free(glob.args_arr);
	while (glob.head)
	{
		temp = glob.head;
		glob.head = glob.head->next;
		free(temp);
	}
}
