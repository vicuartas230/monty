#include "monty.h"

/**
 * push_element - This function add an element at the start of the stack.
 * @head: The start of the stack.
 * @line_number: The element to add.
 * Return: Nothing.
*/

void push_element(stack_t **head, unsigned int line_number)
{
    stack_t *new = NULL;

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = line_number, new->next = NULL, new->prev = NULL;
    if (*head == NULL)
        *head = new;
    else
        new->next = *head, new->next->prev = new, *head = new;
}

/**
 * pall_element - This function prints all the values on the stack, starting
 * from the top of the stack.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void pall_element(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
    stack_t *tmp = *head;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * pint_element - This function prints the value at the top of the 
 * stack, followed by a new line.
 * @head: The start of the stack.
 * @line_number: The number of the text line.
 * Return: Nothing.
 */

void pint_element(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
    printf("%d\n", (*head)->n);
}
