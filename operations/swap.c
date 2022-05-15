/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:38:10 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/15 17:56:13 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

// SWAP LIST A OR B, (SA, SB)
void	swap(t_node **list, char *op)
{
	int	cont_1;
	int	len;

	len = ft_node_list_size(*list);
	if (len < 2)
		return (stupid_move(op));
	cont_1 = (*list)->c;
	(*list)->c = (*list)->n->c;
	(*list)->n->c = cont_1;
	if (op)
		print_operation(op);
}

//SWAP BOTH (SS)
void	swap_ss(t_lists_a_b *lists)
{
	swap(&lists->a, NULL);
	swap(&lists->b, NULL);
	print_operation(SS);
}
