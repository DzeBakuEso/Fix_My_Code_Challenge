#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - Doubly linked list node
 * @n: Integer
 * @prev: Points to the previous node
 * @next: Points to the next node
 *
 * Description: Doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;                /* Integer value of the node */
    struct dlistint_s *prev;  /* Pointer to the previous node */
    struct dlistint_s *next;  /* Pointer to the next node */
} dlistint_t;

size_t print_dlistint(const dlistint_t *h);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
void free_dlistint(dlistint_t *head);

#endif /* LISTS_H */
