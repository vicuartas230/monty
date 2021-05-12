#include "monty.h"

/**
 * free_arr - This function frees an array of pointers.
 * @head: The start of the stack to free.
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
