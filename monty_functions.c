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
	char *buffer = NULL, **opcode = NULL;
	stack_t *head = NULL;
	FILE *scr;

	scr = fopen(bytecode, "r");
	if (!scr)
	{
		printf("Error: Can't open file %s\n", bytecode);
		exit(EXIT_FAILURE);
	}
	while ((chars = getline(&buffer, &n, scr)) != EOF)
	{
		buffer[chars - 1] = ' ';
		words = count_words(buffer, " ");
		if (words > 2)
		{
			printf("L%d: unknown instruction %s\n", i + 1, buffer);
			free(buffer);
			fclose(scr);
			exit(EXIT_FAILURE);
		}
		opcode = str_to_array(buffer, words);
		arg_interpreter(&head, opcode, i + 1);
		free_arr(opcode);
		i++;
	}
	free_stack(head);
	free(buffer);
	fclose(scr);
	return (0);
}

/**
 * arg_interpreter - This function interpretes the opcode entered.
 * @head: The start of the stack.
 * @line: The command to interpretate.
 * @line_number: The line number of the text.
 * Return: 0 (Success)
 */

int arg_interpreter(stack_t **head, char **line, unsigned int line_number)
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
		if (!_strncmp(codes[i].opcode, line[0], _strlen(line[0])))
		{
			if (!strcmp("push", line[0]))
				data = _atoi(line[1]);
			codes[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (!codes[i].opcode)
	{
		printf("L%d: unknown instruction %s\n", line_number, line[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
