#include "monty.h"

/**
 * main - Entry point.
 * @ac: The number of arguments.
 * @av: The arguments storaged in a double pointer.
 * Return: 0 (Success)
 */

int main(int ac, char **av)
{
	/* int ac = 2;
	char *av[2];

	av[0] = "./monty";
	av[1] = "bytecodes/000.m"; */
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	arg_checker(av[1]);
	return (0);
}
