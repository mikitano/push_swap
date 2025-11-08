/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:28:41 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/08 19:14:07 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_process_args(t_dlist *stack_a, char **splited)
{
	int		i;
	long	nbr;

	i = 0;
	while (splited[i])
	{
		if (!ft_valid_number(splited[i]))
			return (false);
		nbr = ft_atol(splited[i]);
		if (nbr < MIN_INT || nbr > MAX_INT)
			return (false);
		if (ft_is_duplicate(stack_a, (int)nbr))
			return (false);
		if (!ft_fill_stack(stack_a, (int)nbr))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_parse_and_fill(t_dlist *stack_a, int argc, char **argv)
{
	char	**splited;
	int		j;

	if (!stack_a || argc < 2 || !argv)
		return (false);
	j = 0;
	while (++j < argc)
	{
		splited = ft_split(argv[j], ' ');
		if (!splited)
			return (false);
		if (argv[j][0] == '\0')
		{
			ft_free_split(splited);
			return (false);
		}
		if (!ft_process_args(stack_a, splited))
		{
			ft_free_split(splited);
			return (false);
		}
		ft_free_split(splited);
	}
	return (true);
}
