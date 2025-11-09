/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:33:03 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 19:38:27 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//#include <stdio.h>
//static void	ft_print(void *head)
//{
//	t_node	*temp;

//	temp = head;
//	while (temp)
//	{
//		printf("%d\n", *(int *)temp->data);
//		temp = temp->next;
//	}
//	printf("\n");
//}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = ft_dlist_initi();
	if (!stack_a)
		return (1);
	stack_b = ft_dlist_initi();
	if (!stack_b)
		return (1);
	if (!ft_parse_and_fill(stack_a, argc, argv))
	{
		ft_destroy_dlst(&stack_a, free);
		ft_destroy_dlst(&stack_b, free);
		write(2, "Error\n", 6);
		exit (1);
	}
	ft_sort(stack_a, stack_b);
	//ft_print(stack_a->head);
	ft_destroy_dlst(&stack_a, free);
	ft_destroy_dlst(&stack_b, free);
	return (0);
}
