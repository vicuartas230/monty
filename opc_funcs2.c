#include "monty.h"

/**
 * add_element - This function adds the top two elements of the stack.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void add_element(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	unsigned int i = 0;
	int res = 0;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	res += tmp->n;
	tmp = tmp->next;
	res += tmp->n;
	tmp->n = res;
	pop_element(head, line_number);
}

/**
 * nop_element - This function doesn’t do anything.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void nop_element(__attribute__((unused))stack_t **head, __attribute__(
	(unused))unsigned int line_number)
{}
