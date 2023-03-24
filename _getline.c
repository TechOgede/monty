#include "monty.h"

/**
* _getline - reads one line at a time from a file
* @line: memory buffer to contain input read
* @len: size of buffer
* @fp: file pointer
*
* Description: reads from file and dynamically allocates memory
* Return: no of bytes read, or -1 on error or end of file
*/
ssize_t _getline(char **line, size_t *len, FILE *fp)
{
	char chunk[128];

	if (!line || !len || !fp)
		return (-1);
	if (*line == NULL)
	{
		*len = sizeof(chunk);
		*line = malloc(*len);
		if (*line == NULL)
			return (-1);
	}
	(*line)[0] = '\0';
	while (fgets(chunk, sizeof(chunk), fp) != NULL)
	{
		if (*len - _strlen(*line) < sizeof(chunk))
		{
			*len = *len * 2;
			*line = _realloc(*line, (*len / 2), *len);
			if (*line == NULL)
			{
				free(*line);
				return (-1);
			}
		}
		_strcat(*line, chunk);
		if ((*line)[_strlen(*line) - 1] == '\n')
			return (_strlen(*line));
	}
	return (-1);
}
