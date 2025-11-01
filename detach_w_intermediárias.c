#include "push_swap.h"

t_node	*ft_detach(t_dlist *lst, t_node *node_to_detach)
{
	t_node	*prev_node;
	t_node	*next_node;

	if (!lst || !node_to_detach)
	return (NULL);
	prev_node = node_to_detach->prev;
	next_node = node_to_detach->next;
	if (node_to_detach->prev)
		prev_node->next = next_node;
	if (node_to_detach->next)
		next_node->prev = prev_node;
	if (lst->head == node_to_detach)
		lst->head = next_node;
	if (lst->tail == node_to_detach)
		lst->tail = prev_node;
	lst->size--;
	node_to_detach->next = NULL;
	node_to_detach->prev = NULL;
	return (node_to_detach);
}
