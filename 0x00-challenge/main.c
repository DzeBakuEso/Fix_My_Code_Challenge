#include <stdio.h>
#include "lists.h"

/**
 * main - Entry point to the program
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    dlistint_t *head = NULL;

    /* Add nodes to the list */
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    
    print_dlistint(head);
    printf("-----------------\n");

    /* Delete nodes at various indexes */
    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");
    
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Continue with other delete operations and printing */
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Continue deleting until the list is empty */
    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    delete_dnodeint_at_index(&head, 0);
    print_dlistint(head);
    printf("-----------------\n");

    /* Clean up the remaining nodes */
    delete_dnodeint_at_index(&head, 0);
    free_dlistint(head);

    return (0);
}
