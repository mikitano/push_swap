#include "push_swap.h"

static int	ft_get_max_bits(t_dlist *stack_a)
{
	int		bits;
	int		max;
	t_node	*temp;

	max = 0;
	bits = 0;
	temp = stack_a->head;
	while (temp)
	{
		if ((int)temp->index > max)
			max = (int)temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix_bsort(t_dlist *stack_a, t_dlist *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	num_index;

	max_bits = ft_get_max_bits(stack_a);
	size = stack_a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && stack_a->head)
		{
			num_index = (int)stack_a->head->index;
			if (((num_index >> i) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a, stack_a->head, 1);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
