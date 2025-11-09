/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:43:30 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 18:12:29 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_give_index(t_dlist *stack_a)
{
	t_node	*temp;
	t_node	*current;
	size_t	count;

	current = stack_a->head;
	while (current)
	{
		count = 0;
		temp = stack_a->head;
		while (temp)
		{
			if (*(int *)current->data > *(int *)temp->data)
				count++;
			temp = temp->next;
		}
		current->index = count;
		current = current->next;
	}
}


void	ft_sort(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_give_index(stack_a);
	if (ft_is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
	{
		ft_sort_two(stack_a);
		return ;
	}
	else if (stack_a->size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	else if (stack_a->size <= 5)
	{
		ft_sort_five(stack_a, stack_b);
		return ;
	}
	//else
	//	ft_radix(stack_a, stack_b);
}
