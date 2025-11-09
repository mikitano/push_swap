/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:45:31 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 19:30:50 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_min(t_dlist *stack_a, int position)
{
	t_node	*temp;
	t_node	*temp_t;
	int		rotate;

	rotate = 0;
	temp = stack_a->head;
	if (position <= (int)stack_a->size / 2)
	{
		while (position--)
		{
			temp = stack_a->head;
			ra(stack_a, temp, 1);
		}
	}
	else
	{
		rotate = ((int)stack_a->size - position);
		while (rotate--)
		{
			temp_t = stack_a->tail;
			rra(stack_a, temp_t, 1);
		}
	}
}

void	ft_min_to_top(t_dlist *stack_a)
{
	t_node	*temp;
	int		min;
	int		position;
	int		i;

	temp = stack_a->head;
	min = *(int *)temp->data;
	position = 0;
	i = 0;
	while (temp)
	{
		if (*(int *)temp->data < min)
		{
			min = *(int *)temp->data;
			position = i;
		}
		temp = temp->next;
		i++;
	}
	ft_move_min(stack_a, position);
}
