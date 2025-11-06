/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:03:14 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/02 11:35:46 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_dlist *stack_a, t_node *to_move, int print)
{
	if (!stack_a || !to_move)
		return ;
	ft_detach(stack_a, to_move);
	ft_push_node_back(stack_a, to_move);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_dlist *stack_b, t_node *to_move, int print)
{
	if (!stack_b || !to_move)
		return ;
	ft_detach(stack_b, to_move);
	ft_push_node_back(stack_b, to_move);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b)
{
	if (!stack_a || !stack_b || !node_a || !node_b)
		return ;
	ra(stack_a, node_a, 0);
	rb(stack_b, node_b, 0);
	ft_putstr_fd("rr\n", 1);
}
