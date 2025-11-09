/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:21:52 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 19:24:04 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_dlist *stack_a)
{
	t_node	*temp;

	if (stack_a->size == 1)
	{
		write(1, "Already sorted\n", 15);
		return (true);
	}
	temp = stack_a->head;
	while (temp->next)
	{
		if (*(int *)temp->data > *(int *)temp->next->data)
			return (false);
		temp = temp->next;
	}
	write(1, "Already sorted!\n", 15);
	return (true);
}

void	ft_sort_two(t_dlist *stack_a)
{
	t_node	*temp;

	temp = stack_a->head;
	if (*(int *)temp->data > *(int *)temp->next->data)
		sa(stack_a, temp, 1);

	else
		return ;
}

void	ft_sort_three(t_dlist *stack_a)
{
	t_node	*temp;
	t_node	*check;

	temp = stack_a->head;
	if (!temp || !temp->next || !temp->next->next)
		return ;
	if (*(int *)temp->data > *(int *)temp->next->data)
	{
		if (*(int *)temp->data > *(int *)temp->next->next->data)
			ra(stack_a, temp, 1);
	}
	else if (*(int *)temp->data < *(int *)temp->next->data)
	{
		temp = temp->next;
		if (*(int *)temp->data > *(int *)temp->next->data)
			rra(stack_a, temp->next, 1);
	}
	check = stack_a->head;
	if (*(int *)check->data > *(int *)check->next->data)
		sa(stack_a, check, 1);
}

void	ft_sort_five(t_dlist *stack_a, t_dlist *stack_b)
{
	while (stack_a->size > 3)
	{
		ft_min_to_top(stack_a);
		pb(stack_b, stack_a);
	}
	ft_sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
