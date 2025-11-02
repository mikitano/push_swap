/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:57:55 by mkitano           #+#    #+#             */
/*   Updated: 2025/11/02 11:11:24 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
//add o caminho da pasta depois
# include "libft.h"

typedef struct s_node
{
	void			*data;
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

void	ft_delete_one(t_node *to_delete, void (*del)(void*));
void	ft_clear_all_nodes(t_dlist *lst, void (*del)(void*));
void	ft_destroy_dlst(t_dlist **lst, void (*del)(void*));

#endif