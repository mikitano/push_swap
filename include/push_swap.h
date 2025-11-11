/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:57:55 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/09 18:37:19 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# include "libft.h"

typedef struct s_node
{
	void			*data;
	size_t			index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_dlist
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_dlist;

t_dlist	*ft_dlist_initi(void);
t_node	*ft_new_node(void *data);
t_node	*ft_detach(t_dlist *lst, t_node *node_to_detach);

int		ft_push_node_back(t_dlist *lst, t_node *to_add);
int		ft_push_node_front(t_dlist *lst, t_node *to_add);
t_node	*ft_get_node_at(t_dlist *lst, size_t index);
int		ft_insert_node_at(t_dlist *lst, t_node *node, size_t index);

void	ft_destroy_dlst(t_dlist **lst, void (*del)(void*));

void	sa(t_dlist *stack_a, t_node *to_move, int print);
void	sb(t_dlist *stack_b, t_node *to_move, int print);
void	ss(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b);
void	pa(t_dlist *stack_a, t_dlist *stack_b);
void	pb(t_dlist *stack_b, t_dlist *stack_a);
void	ra(t_dlist *stack_a, t_node *to_move, int print);
void	rb(t_dlist *stack_b, t_node *to_move, int print);
void	rr(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b);
void	rra(t_dlist *stack_a, t_node *to_move, int print);
void	rrb(t_dlist *stack_b, t_node *to_move, int print);
void	rrr(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b);

int		ft_valid_number(char *str);
long	ft_atol(const char *str);
bool	ft_is_duplicate(t_dlist *stack_a, int nbr);
bool	ft_fill_stack(t_dlist *stack_a, int nbr);
void	ft_free_split(char **split);
bool	ft_parse_and_fill(t_dlist *stack_a, int argc, char **argv);

bool	ft_is_sorted(t_dlist *stack_a);
void	ft_sort_two(t_dlist *stack_a);
void	ft_sort_three(t_dlist *stack_a);
void	ft_sort_five(t_dlist *stack_a, t_dlist *stack_b);
void	ft_min_to_top(t_dlist *stack_a);

void	ft_radix_bsort(t_dlist *stack_a, t_dlist *stack_b);

void	ft_sort(t_dlist *stack_a, t_dlist *stack_b);

#endif
