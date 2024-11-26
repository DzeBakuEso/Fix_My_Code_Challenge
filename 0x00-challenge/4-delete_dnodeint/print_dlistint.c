#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints all the elements of a doubly linked list
 * @h: Pointer to the first element of the list
 *
 * Return: The number of nodes printed
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t n = 0;

    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
        n++;
    }
    return (n);
}
