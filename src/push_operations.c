/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:33:51 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 18:37:14 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_dlist *stack_a, t_dlist *stack_b)
{
	t_node	*to_move;

	to_move = stack_b->head;
	if (!stack_a || !stack_b || !to_move)
		return ;
	ft_detach(stack_b, to_move);
	ft_push_node_front(stack_a, to_move);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_dlist *stack_b, t_dlist *stack_a)
{
	t_node	*to_move;

	to_move = stack_a->head;
	if (!stack_a || !stack_b || !to_move)
		return ;
	ft_detach(stack_a, to_move);
	ft_push_node_front(stack_b, to_move);
	ft_putstr_fd("pb\n", 1);
}
