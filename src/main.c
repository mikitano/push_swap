/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:52:06 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/02 18:31:35 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_node *head)
{
	t_node	*temp;

	temp = head;
	printf("Foward: ");
	while (temp)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// main test
int	main(void)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;

	stack_a = ft_dlist_initi;
	stack_b = ft_dlist_initi;
	tmp1 = ft_new_node(10);
	tmp2 = ft_new_node(42);
	tmp3 = ft_new_node(2);
	tmp1->next = tmp2;
	tmp2->prev = tmp1;
	tmp2->next = tmp3;
	tmp3->prev = tmp2;
	stack_a->head = tmp1;
	stack_a->tail = tmp3;
	stack_a->size = 3;
	ft_print(temp1);
}
