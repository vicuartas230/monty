#include "monty.h"

/**
 * arg_checker - This function checks if the argument is valid.
 * @bytecode: The argument to check.
 * Return: -1 if it fails or 0 on success.
 */

int arg_checker(char *bytecode)
{
	int fd = 0, lines = 0, i = 0;
	ssize_t chars = 0;
	char buffer[BUFSIZ], **opcode = NULL, *opc = NULL, *arg = NULL;
	stack_t *head = NULL;

	fd = open(bytecode, O_RDONLY);
	if (fd == -1)
		return (-1);
	chars = read(fd, buffer, BUFSIZ);
	if (chars == -1)
		return (-1);
	lines = count_lines(buffer, "\n");
	opcode = str_to_array(buffer, lines);
	if (!opcode)
		return (-1);
	while (opcode[i])
	{
		opc = separate_opc(opcode[i]);
		arg = separate_arg(opcode[i]);
		arg_interpreter(&head, opc, _atoi(arg));
		free(opc);
		free(arg);
		i++;
	}
	free_arr(opcode);
	if (head)
		free_stack(head);
	return (0);
}

/**
 * arg_interpreter - This function interpretes the opcode entered.
 * @head: The start of the stack.
 * @line: The command to interpretate.
 * @line_number: The line number of the text.
 * Return: 0 (Success)
 */

int arg_interpreter(stack_t **head, char *line, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t codes[] = {
		{"push", push_element},
		{"pall", pall_element},
		{"pint", pint_element},
		{"pop", pop_element},
		{"swap", swap_element},
		{"add", add_element},
		{"nop", nop_element},
		{NULL, NULL},
	};

	while (codes[i].opcode)
	{
		if (!_strncmp(codes[i].opcode, line, 3))
		{
			codes[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (!codes[i].opcode)
		return (-1);
	return (0);
}
