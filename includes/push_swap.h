/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:33:13 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/10 18:48:55 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

// NODES
t_node	*ft_new_node(int content);
void	ft_node_add_back(t_node **node_lst, t_node *new_node);
void	ft_node_iter(t_node *lst, void (*f)(void *));
int		ft_node_list_size(t_node *lst);

// ACTIONS
void	swap_top(t_node **list_a);
void	push_top(t_node **list_from, t_node **list_to);

// STATUS
void status_nodes(t_node *head_node);


#endif