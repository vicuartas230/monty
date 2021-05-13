#include "monty.h"

/**
 * _atoi - This function converts a string in a number.
 * @str: The string to convert.
 * Return: The number converted.
 */

int _atoi(unsigned int line_number, stack_t **head)
{
	int i = strlen(data.op_c[1]) - 1, j = 0, num = 0;

	if (data.op_c[1][0] == '-' && _strlen(data.op_c[1]) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	while (data.op_c[1][j])
	{
		if (data.op_c[1][j] == '-')
		{
			j++;
			continue;
		}
		if (data.op_c[1][j] < '0' || data.op_c[1][j] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(data.buffer);
			free_arr(data.op_c);
			fclose(data.scr);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		num += (data.op_c[1][i] - '0') * _pow(10, j);
		i--;
		j++;
	}
	if (data.op_c[1][0] == '-')
		num = -num / 10;
	return (num);
}

/**
 * _pow - This function raises a number to the power y.
 * @x: The number to raise.
 * @y: The power to raise x.
 * Return: The result of the power.
 */

int _pow(unsigned int x, unsigned int y)
{
	int res = 1;
	unsigned int i = 0;

	while (i < y)
	{
		res *= x;
		i++;
	}
	return (res);
}

/**
 * free_stack - This function frees a stack.
 * @head: The start of the stack to free.
 * Return: Nothing.
 */

void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (tmp)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}

/**
 * free_arr - This function frees an array of pointers.
 * @str: The start of the stack to free.
 * Return: Nothing.
 */

void free_arr(char **str)
{
	unsigned int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
