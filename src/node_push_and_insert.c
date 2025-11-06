/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_insert_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:26:53 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/01 17:37:37 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_node_back(t_dlist *lst, t_node *to_add)
{
	if (!lst || !to_add)
		return (0);
	to_add->next = NULL;
	to_add->prev = lst->tail;
	if (lst->size == 0)
		lst->head = to_add;
	else
		lst->tail->next = to_add;
	lst->tail = to_add;
	lst->size++;
	return (1);
}

int	ft_push_node_front(t_dlist *lst, t_node *to_add)
{
	if (!lst || !to_add)
		return (0);
	to_add->prev = NULL;
	to_add->next = lst->head;
	if (lst->size == 0)
		lst->tail = to_add;
	else
		lst->head->prev = to_add;
	lst->head = to_add;
	lst->size++;
	return (1);
}

t_node	*ft_get_node_at(t_dlist *lst, size_t index)
{
	t_node	*current;
	size_t	i;

	if (!lst || index >= lst->size)
		return (NULL);
	if (index < lst->size / 2)
	{
		current = lst->head;
		i = 0;
		while (i++ < index)
			current = current->next;
	}
	else
	{
		current = lst->tail;
		i = lst->size - 1;
		while (i-- > index)
			current = current->prev;
	}
	return (current);
}

int	ft_insert_node_at(t_dlist *lst, t_node *node, size_t index)
{
	t_node	*node_at_index;

	if (!lst || !node || index > lst->size)
		return (0);
	if (index == 0)
		return (ft_push_node_front(lst, node));
	if (index == lst->size)
		return (ft_push_node_back(lst, node));
	node_at_index = ft_get_node_at(lst, index);
	node->prev = node_at_index->prev;
	node->next = node_at_index;
	node_at_index->prev->next = node;
	node_at_index->prev = node;
	lst->size++;
	return (1);
}

