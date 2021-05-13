#include "monty.h"

/**
 * push_element - This function add an element at the start of the stack.
 * @head: The start of the stack.
 * @line_number: The element to add.
 * Return: Nothing.
*/

void push_element(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!line_number)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (!data.op_c[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new->n = _atoi(line_number, head);
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		new->next->prev = new;
		*head = new;
	}
}

/**
 * pall_element - This function prints all the values on the stack, starting
 * from the top of the stack.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void pall_element(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!line_number)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint_element - This function prints the value at the top of the
 * stack, followed by a new line.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void pint_element(stack_t **head, unsigned int line_number)
{
	if (!line_number)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_element - This function removes the first element in the stack.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void pop_element(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!line_number)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else if (!tmp->next)
	{
		free(tmp);
		*head = NULL;
		head = NULL;
	}
	else
	{
		tmp = tmp->next;
		free(*head);
		tmp->prev = NULL;
		*head = tmp;
	}
}

/**
 * swap_element - This function swaps the top two elements of the stack.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void swap_element(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	unsigned int i = 0;

	if (line_number < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	tmp->next->prev = NULL;
	tmp->prev = *head;
	tmp->next = tmp->prev->next;
	tmp->prev->next = tmp;
	tmp->next->prev = tmp;
}
