#include "monty.h"

/**
 * main - Entry point.
 * @ac: The number of arguments.
 * @av: The arguments storaged in a double pointer.
 * Return: 0 (Success)
 */

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    if (access(av[1], F_OK) == -1)
    {
        printf("Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    arg_checker(av[1]);
    return (0);
}