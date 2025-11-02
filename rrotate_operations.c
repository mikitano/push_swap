/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:08:59 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/02 14:18:07 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_dlist *stack_a, t_node *to_move, int print)
{
	if (!stack_a || !to_move)
		return ;
	ft_detach(stack_a, to_move);
	ft_push_node_front(stack_a, to_move);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_dlist *stack_b, t_node *to_move, int print)
{
	if (!stack_b || !to_move)
		return ;
	ft_detach(stack_b, to_move);
	ft_push_node_front(stack_b, to_move);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b)
{
	if (!stack_a || !stack_b || !node_a || !node_b)
		return ;
	rra(stack_a, node_a, 0);
	rrb(stack_b, node_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
