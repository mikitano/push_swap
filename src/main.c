/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:33:03 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/06 19:42:35 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_dlist_initi();
	stack_b = ft_dlist_initi();

	// add validação e sorting

	ft_destroy_dlst(&stack_a, free);
	ft_destroy_dlst(stack_b, free);
	return (0);
}