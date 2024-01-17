#include "sort.h"
/**
 * insertion_sort_list - sort doubly linked list
 * @list: pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *temp = NULL, *head = NULL;
	int len;
	
	if (list == NULL || (*list) == NULL)
		return;

	head = *list;
	len = 0;

	while (head != NULL)
	{
		head = head->next;
		len++;
	}

	node = (*list);

	if (len < 2)
		return;

	while (node)
	{
		while (node->next && node->n > node->next->n)
		{
			temp = node->next;
			temp->prev = node->prev;
			node->next = temp->next;
			if (node->prev != NULL)
				node->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = node;
			node->prev = temp;
			temp->next = node;
			if (temp->prev != NULL)
				node = temp->prev;
			else
				*list = temp;
			print_list(*list);
		}
		node = node->next;
	}
	return;
}
