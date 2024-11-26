#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a given position
 * @head: Pointer to the head of the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp;
    unsigned int i = 0;

    if (!*head)
        return (-1);

    temp = *head;

    /* Check if the list is empty */
    if (index == 0)
    {
        *head = temp->next;
        if (*head)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    while (temp && i < index)
    {
        temp = temp->next;
        i++;
    }

    if (!temp)
        return (-1);

    if (temp->next)
        temp->next->prev = temp->prev;

    if (temp->prev)
        temp->prev->next = temp->next;

    free(temp);

    return (1);
}
