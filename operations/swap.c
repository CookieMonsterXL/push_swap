/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:38:10 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/17 15:48:45 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

// SWAP LIST A OR B, (SA, SB)
void	swap(t_node **list, char *op)
{
	t_node	*temp;
	t_node	*temp1;
	int		len;

	temp = *list;
	temp1 = temp->n;
	len = ft_list_size(*list);
	if (len < 2)
		return (stupid_move(op));
	temp1->n = temp;
	temp1->p = NULL;
	if (len > 2)
	{
		temp->p = temp->n;
		temp->n = temp->n->n;
	}
	else
	{
		temp->n = NULL;
		temp->p = temp1;
	}
	*list = temp1;
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
