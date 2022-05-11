/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:33:13 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/11 12:49:04 by tbouma           ###   ########.fr       */
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

typedef struct s_list_a_b
{
	struct s_node	**a;
	struct s_node	**b;
}	t_lists_a_b;

// NODES
t_node	*ft_new_node(int content);
void	ft_node_add_back(t_node **node_lst, t_node *new_node);
void	ft_node_iter(t_node *lst, void (*f)(void *));
int		ft_node_list_size(t_node *lst);

// ACTIONS
void	swap_top(t_node **list_a, char *op);
void	push_top(t_node **list_from, t_node **list_to, char *op);

// STATUS
void	status_nodes(t_node **head_node_a, t_node **head_node_b);

// PRINT
void	print_operation(char *operation);

// DIFINE
# define SA		"sa\n"
# define SB		"sb\n"
# define SS		"ss\n"
# define PA		"pa\n"
# define PB		"pb\n"



#endif