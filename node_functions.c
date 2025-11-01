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

//checar esse role, ver der fazer sem criar um novo só mexeno posição
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

t_node	*detach_first(t_node **head)
{
	t_node	*first_alone;

	first_alone = *head;
	if (!*head)
		return (NULL);
	*head = (*head)->next;
	(*head)->prev = NULL;
	first_alone->prev = NULL;
	first_alone->next = NULL;
	return (first_alone);
}

t_node	*detach_last(t_node **head)
{
	
}