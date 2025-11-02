/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:20:35 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/02 14:31:37 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_dlist *stack_a, t_node *to_move, int print)
{
	if (!stack_a || !to_move || stack_a->size == 1)
		return ;
	ft_detach(stack_a, to_move);
	ft_insert_node_at(stack_a, to_move, 2);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_dlist *stack_b, t_node *to_move, int print)
{
	if (!stack_b || !to_move || stack_b->size == 1)
		return ;
	ft_detach(stack_b, to_move);
	ft_insert_node_at(stack_b, to_move, 2);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b)
{
	if (!stack_a || !stack_b || !node_a || !node_b)
		return ;
	if (stack_a->size == 1 || stack_b->size == 1)
		return ;
	sa(stack_a, node_a, 0);
	sb(stack_b, node_b, 0);
	ft_putstr_fd("ss\n", 1);
}
