#ifndef MONTY_H
#define MONTY_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global_vars - global variables
* @stack: 1 if stack, 0 if queue
* @fp: pointer to a bytecode file
* @arg: argument from the file
* @head: pointer to the stack (or queue)
* @line_num: current line  of file
* @buf: array of tokenised input
*
* Description: global variables structure
*/
typedef struct global_vars
{
	int stack;
	FILE *fp;
	char *arg;
	stack_t *head;
	int line_num;
	char *buf;
	char **args_arr;
} global_t;

extern global_t glob;

FILE *check_file(int argc, char **argv);
void (*opc(char *arg, size_t line))
(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void push_stack(stack_t **stack, int n);
void pall(stack_t **stack, unsigned int line_number);
void free_glob(void);
void init_global_vars(FILE *fp);

/* str functions*/
char *_strtok(char *str, char *delim);
int _strspn(char *s, char *accept);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strlen(const char *s);

/* memory functions*/
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **line, size_t *len, FILE *fp);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
#endif
