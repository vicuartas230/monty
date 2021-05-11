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
    if (!*head)
        *head = new;
    else
        new->next = *head, new->next->prev = new, *head = new;
}

void pall_element(stack_t **head, unsigned int line_number)
{
    stack_t *tmp = *head;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
