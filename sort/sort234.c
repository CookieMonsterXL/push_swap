/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort234.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:02:50 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 13:47:38 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	sort2_b(t_node **list_b)
{
	if ((*list_b)->i < (*list_b)->n->i)
		swap(list_b, SB);
}

void	sort2(t_node **list_a)
{
	if ((*list_a)->c > (*list_a)->n->c)
		swap(list_a, SA);
}

void	sort3(t_node **list_a)
{
	if ((*list_a)->c > (*list_a)->n->c)
	{
		if ((*list_a)->c > (*list_a)->n->n->c)
		{
			if ((*list_a)->n->c > (*list_a)->n->n->c)
			{
				swap(list_a, SA);
				r_rotate(list_a, RRA);
			}
			else
				rotate(list_a, RA);
		}
		else
			swap(list_a, SA);
	}
	else
	{
		if ((*list_a)->c > (*list_a)->n->n->c)
			r_rotate(list_a, RRA);
		if ((*list_a)->n->c > (*list_a)->n->n->c)
		{
			swap(list_a, SA);
			rotate(list_a, RA);
		}
	}
}

void	sort_h_4(t_lists_a_b *lists)
{
	t_node	*last_a;

	while (lists->b)
	{
		last_a = ft_list_find_last_node(&lists->a);
		if (lists->a->i > lists->b->i && last_a->i < lists->b->i)
			push(lists, PA);
		else if (lists->a->i == 1 && lists->b->i == 0)
			push(lists, PA);
		else if (lists->a->i == 0 && lists->b->i == 3)
			push(lists, PA);
		else if (last_a->i > lists->b->i && last_a->p->i < lists->b->i)
			r_rotate(&lists->a, RRA);
		else
			rotate(&lists->a, RA);
	}
}

void	sort4(t_lists_a_b *lists)
{
	t_node	*last_a;

	if (ft_list_check_sorted(&lists->a))
		return ;
	last_a = ft_list_find_last_node(&lists->a);
	push(lists, PB);
	sort3(&lists->a);
	sort_h_4(lists);
	last_a = ft_list_find_last_node(&lists->a);
	while (lists->a->i > last_a->i)
	{
		last_a = last_a->p;
		r_rotate(&lists->a, RRA);
		last_a = ft_list_find_last_node(&lists->a);
	}
}
