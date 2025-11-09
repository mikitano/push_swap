/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_initi_create_detach.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:57:42 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 11:40:36 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dlist_initi(void)
{
	t_dlist	*d_list;

	d_list = (t_dlist *)malloc(sizeof(t_dlist));
	if (!d_list)
		return (NULL);
	d_list->head = NULL;
	d_list->tail = NULL;
	d_list->size = 0;
	return (d_list);
}

t_node	*ft_new_node(void *data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*ft_detach(t_dlist *lst, t_node *node_to_detach)
{
	if (!lst || !node_to_detach)
		return (NULL);
	if (node_to_detach->prev)
		node_to_detach->prev->next = node_to_detach->next;
	if (node_to_detach->next)
		node_to_detach->next->prev = node_to_detach->prev;
	if (lst->head == node_to_detach)
		lst->head = node_to_detach->next;
	if (lst->tail == node_to_detach)
		lst->tail = node_to_detach->prev;
	lst->size--;
	node_to_detach->next = NULL;
	node_to_detach->prev = NULL;
	return (node_to_detach);
}