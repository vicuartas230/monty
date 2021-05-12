#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int arg_checker(char *bytecode);
int arg_interpreter(stack_t **head, char *line, unsigned int line_number);
char **str_to_array(char *str, unsigned int lines);
char *_strdup(const char *s);
int count_lines(char *buff, char *delim);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
void push_element(stack_t **head, unsigned int line_number);
void pall_element(stack_t **head, unsigned int line_number);
void pint_element(stack_t **head, unsigned int line_number);
void pop_element(stack_t **head, unsigned int line_number);
void swap_element(stack_t **head, unsigned int line_number);
void add_element(stack_t **head, unsigned int line_number);
void nop_element(stack_t **head, unsigned int line_number);
char *separate_arg(char *str);
char *separate_opc(char *str);
int _atoi(char *str);
int _pow(unsigned int x, unsigned int y);
void free_stack(stack_t *head);
void free_arr(char **str);

#endif
