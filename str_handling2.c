#include "monty.h"

/**
 * _atoi - This function converts a string in a number.
 * @str: The string to convert.
 * Return: The number converted.
 */

int _atoi(char *str)
{
	int i = strlen(str) - 1, j = 0, num = 0;

	if (!str[j])
		return (num);
	while (str[j])
	{
		if (str[j] == '-')
		{
			j++;
			continue;
		}
		num += (str[i] - '0') * _pow(10, j);
		i--;
		j++;
	}
	if (str[0] == '-')
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
