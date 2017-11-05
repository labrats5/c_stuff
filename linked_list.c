#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list *next;
} lnode;

lnode *find_middle (lnode *head)
{
	lnode *middle = head;
	lnode *end = head;
	int i = 0;

	while (end)
	{
		end = end->next;
		if (i % 2) middle = middle->next;
		i++;
	}
	return middle;
}

lnode *third_from_last (lnode *head)
{
	lnode *trailing = NULL;
	lnode *end = head;
	int i = 1;

	while (end && i<3)
	{
		end = end->next;
		i++;
	}

	trailing = head;

	while (end)
	{
		end = end->next;
		middle = middle->next;
	}
	return trailing;
}

int list_length (lnode *head)
{
	int i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return i;
}

void add_to_list (lnode *head, lnode *node)
{
	if (!head)
	{
		head = node;
	}
	else
	{
		while (head->next)
		{
			head = head->next;
		}
		head->next = node;
	}
}
