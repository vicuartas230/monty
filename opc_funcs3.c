#include "monty.h"

/**
 * mod_element - This function computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void mod_element(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (!tmp->n)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	res = tmp->n % tmp->prev->n;
	tmp->n = res;
	pop_element(head, line_number);
}
