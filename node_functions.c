#include "push_swap.h"

t_node	*create_new_node(int i)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	new_node->data = i;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	insert_node_at_tail(int numb, t_node **head)
{
	t_node	*newNode;
	t_node	*temp;

	newNode = create_new_node(numb);
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
}

t_node	*detach_node(t_node **head, t_node *node_to_isolate??)
{
	t_node *alone_node;

	
}