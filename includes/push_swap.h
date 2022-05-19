#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:33:13 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/13 15:45:54 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

int		*g_op_counter; //GLOBEL COUNTER REMOVE LATER

//c = content, n = next, p = previous
typedef struct s_node
{
	int				c;
	int				i;
	struct s_node	*n;
	struct s_node	*p;
}	t_node;

typedef struct s_list_a_b
{
	struct s_node	*a;
	struct s_node	*b;
}	t_lists_a_b;

typedef struct s_bucket
{
	int	limit_hi;
	int	limit_lo;
	int	amount_buckets;
	int	number;
}	t_bucket;

// NODES
t_node	*ft_new_node(int c);
void	ft_list_node_add_back(t_node **node_lst, t_node *new_node);
void	ft_node_iter(t_node *lst, void (*f)(void *));
int		ft_list_size(t_node *lst);
t_node	*ft_list_find_last_node(t_node **list);
int		ft_list_check_sorted(t_node **list);
void	ft_list_make_index(t_node **list_a);

// ACTIONS
// void	swap_OLD(t_node **list_a, char *op);
// void	push_OLD(t_node **list_from, t_node **list_to, char *op);
void	swap(t_node **list, char *op);
void	swap_ss(t_lists_a_b *lists);
void	push(t_lists_a_b *lists, char *op);
void	rotate(t_node **list, char *op);
void	rotate_rr(t_lists_a_b *lists);
void	r_rotate(t_node **list, char *op);
void	r_rotate_rr(t_lists_a_b *lists);

// SORT
void	sort2(t_node **list_a);
void	sort3(t_node **list_a);
void	sort5(t_lists_a_b *lists);

void	bucketsort(t_lists_a_b *lists);

int	find_amount_of_buckets(int length_list);

// STATUS
void	status_nodes(t_node **head_node_a, t_node **head_node_b);

// PRINT
void	print_operation(char *operation);
void	stupid_move(char *op);

// DIFINE
# define SA		"sa\n"
# define SB		"sb\n"
# define SS		"ss\n"
# define PA		"pa\n"
# define PB		"pb\n"
# define RA		"ra\n"
# define RB		"rb\n"
# define RR		"rr\n"
# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

#endif