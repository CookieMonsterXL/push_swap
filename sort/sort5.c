/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:27:41 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 12:30:49 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	sort_h_5(t_lists_a_b *lists)
{
	t_node	*last_a;

	while (lists->b)
	{
	last_a = ft_list_find_last_node(&lists->a);
		if (lists->a->i > lists->b->i && last_a->i < lists->b->i)
			push(lists, PA);
		else if (lists->a->i == 1 && lists->b->i == 0)
			push(lists, PA);
		else if (lists->a->i == 0 && lists->b->i == 4)
			push(lists, PA);
		else if (lists->a->i == 1 && lists->b->i == 4 && lists->b->n->i == 0)
			push(lists, PA);
		else if (lists->a->i == 2 && lists->b->i == 1 && lists->b->n->i == 0)
			push(lists, PA);
		else if (last_a->i > lists->b->i && last_a->p->i < lists->b->i)
			r_rotate(&lists->a, RRA);
		else
			rotate(&lists->a, RA);
	}
}

void	sort5(t_lists_a_b *lists)
{
	t_node	*last_a;

	if (ft_list_check_sorted(&lists->a))
		return ;
	last_a = ft_list_find_last_node(&lists->a);
	push(lists, PB);
	push(lists, PB);
	sort2_b(&lists->b);
	sort3(&lists->a);
	while (lists->b)
		sort_h_5(lists);
	last_a = ft_list_find_last_node(&lists->a);
	while (lists->a->c > last_a->c)
	{
		last_a = last_a->p;
		r_rotate(&lists->a, RRA);
		last_a = ft_list_find_last_node(&lists->a);
	}
}
