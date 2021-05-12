#include "monty.h"

/**
 * separate_opc - This function separates the command in each line.
 * @str: String to separate.
 * Return: The string separated.
 */

char *separate_opc(char *str)
{
	unsigned int i = 0;
	char *new = NULL;

	new = malloc((_strlen(str) + 1) * sizeof(char));
	if (!new)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (str[i] && str[i] != ' ')
		new[i] = str[i], i++;
	new[i] = '\0';
	return (new);
}

/**
 * separate_arg - This function separates the argument of the opcode.
 * @str: The string to separate.
 * Return: The string without the command.
 */

char *separate_arg(char *str)
{
	unsigned int i = 0, j = 0;
	char *new = NULL;

	while (str[i] && str[i] != ' ')
		i++;
	i++;
	new = malloc((_strlen(str) - i + 1) * sizeof(char));
	if (!new)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("L<line_number>: usage: push integer\n");
			exit(EXIT_FAILURE);
		}
		new[j] = str[i], j++, i++;
	}
	new[j] = '\0';
	return (new);
}

/**
 * _atoi - This function converts a string in a number.
 * @str: The string to convert.
 * Return: The number converted.
 */

int _atoi(char *str)
{
	unsigned int i = strlen(str) - 1, j = 0, num = 0;

	if (!str[j])
		return (num);
	while (str[j])
		num += (str[i] - '0') * _pow(10, j), i--, j++;
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
