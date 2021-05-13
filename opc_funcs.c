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
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = data;
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
		printf("L<line_number>: can't pint, stack empty\n");
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
		printf("L<line_number>: can't pop an empty stack\n");
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

void swap_element(stack_t **head, __attribute__(
	(unused))unsigned int line_number)
{
	stack_t *tmp = *head;
	unsigned int i = 0;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		printf("L<line_number>: can't swap, stack too short\n");
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