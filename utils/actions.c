/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:06:03 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/10 18:49:16 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

// SWAP LIST_A OR LIST_B, SA, SB, SS
void	swap_top(t_node **list_a)
{
	t_node	*temp2;
	t_node	*temp3;
	int		len;

	len = ft_node_list_size(*list_a);
	if (len < 2)
		return ;
	temp2 = (*(list_a))->next;
	temp3 = temp2->next;
	if (len > 2)
	{
		temp3->previous = *list_a;
		(*(list_a))->next = temp3;
	}
	else
		(*(list_a))->next = NULL;
	(*(list_a))->previous = temp2;
	temp2->next = *list_a;
	temp2->previous = NULL;
	*list_a = temp2;

}

// void	push_top(t_node **list_from, t_node **list_to)
// {
// 	//t_node	*temp2;

// 	// if (ft_node_list_size(*list_from) < 1)
// 	// 	return ;

// }
