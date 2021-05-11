#include "monty.h"

/**
 * separate_opc - This function separates the command in each line.
 * @lines: String to separate.
 * Return: The string separated.
 */

char *separate_opc(char *str)
{
    unsigned int i = 0;
    char *new = NULL;

    new = malloc((_strlen(str) + 1) * sizeof(char));
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

    while(str[i] && str[i] != ' ')
        i++;
    new = malloc((_strlen(str) - i) * sizeof(char));
    while(str[i] && str[i] != '$')
        new[j] = str[i], j++, i++;
    new[j] = '\0';
    return (new);
}