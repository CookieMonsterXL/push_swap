/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:06:31 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/23 19:12:06 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	push_whole_list_to_a(t_lists_a_b *lists)
{
	while (lists->b)
		push(lists, PA);
}

void	sort_b_hi_to_lo(t_node **list_b)
{
	t_node	*last_b;

	last_b = ft_list_find_last_node(list_b);
	while ((*list_b)->i < last_b->i)
	{
		r_rotate(list_b, RRB);
		last_b = ft_list_find_last_node(list_b);
	}
}