#include "monty.h"

/**
 * arg_checker - This function checks if the argument is valid.
 * @bytecode: The argument to check.
 * Return: -1 if it fails or 0 on success.
 */

int arg_checker(char *bytecode)
{
	int words = 0, i = 0;
	ssize_t chars = 0;
	size_t n = 0;
	stack_t *head = NULL;

	data.scr = fopen(bytecode, "r");
	if (!data.scr)
	{
		printf("Error: Can't open file %s\n", bytecode);
		exit(EXIT_FAILURE);
	}
	while ((chars = getline(&data.buffer, &n, data.scr)) != EOF)
	{
		data.buffer[chars - 1] = ' ';
		words = count_words(data.buffer, " ");
		if (!words)
			continue;
		data.op_c = str_to_array(data.buffer, words);
		arg_interpreter(&head, i + 1);
		free_arr(data.op_c);
		i++;
	}
	free_stack(head);
	free(data.buffer);
	fclose(data.scr);
	return (0);
}

/**
 * arg_interpreter - This function interpretes the data.op_c entered.
 * @head: The start of the stack.
 * @line_number: The line number of the text.
 * Return: 0 (Success)
 */

int arg_interpreter(stack_t **head, unsigned int line_number)
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
		if (!_strncmp(codes[i].opcode, data.op_c[0], _strlen(data.op_c[0])))
		{
			codes[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (!codes[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, data.op_c[0]);
		free(data.buffer);
		free_arr(data.op_c);
		fclose(data.scr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (0);
}
