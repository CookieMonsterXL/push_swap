/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:02:50 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/23 15:34:50 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	sort2(t_node **list_a)
{
	if ((*list_a)->c > (*list_a)->n->c)
		swap(list_a, SA);
}
void	sort2_b(t_node **list_b)
{
	if ((*list_b)->i < (*list_b)->n->i)
		swap(list_b, SB);
}

void	sort3(t_node **list_a)
{
	if ((*list_a)->c > (*list_a)->n->c) //case 1,2,3
	{
		if ((*list_a)->c > (*list_a)->n->n->c) //case 2,3
		{
			if ((*list_a)->n->c > (*list_a)->n->n->c) //case 2
			{
				swap(list_a, SA);
				r_rotate(list_a, RRA);
			}
			else //case 3
				rotate(list_a, RA);
		}
		else //case1
			swap(list_a, SA);
	}
	else // case 4,5
	{
		if ((*list_a)->c > (*list_a)->n->n->c) //case 5
			r_rotate(list_a, RRA);
		if ((*list_a)->n->c > (*list_a)->n->n->c) //case 4
		{
			swap(list_a, SA);
			rotate(list_a, RA);
		}
	}
}
void sort_h_5(t_lists_a_b *lists)
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

void sort_h_4(t_lists_a_b *lists)
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

// static void	sort_h(t_lists_a_b *lists, int len)
// {
// 	t_node	*last_a;

// 	while (lists->b)
// 	{
// 		last_a = ft_list_find_last_node(&lists->a);
// 		if (lists->a->i > lists->b->i && last_a->i < lists->b->i)
// 			push(lists, PA);
// 		else if (lists->a->i == 1 && lists->b->i == 0)
// 			push(lists, PA);
// 		else if (last_a->i > lists->b->i && last_a->p->i < lists->b->i)
// 			r_rotate(&lists->a, RRA);
// 		else if (len == 5)
// 			sort_h_5(lists);
// 		else if (len == 4)
// 			sort_h_4(lists);
// 		else
// 			rotate(&lists->a, RA);

// 		// if (lists->b->c > lists->a->c && lists->b->c < lists->a->n->c)
// 		// {
// 		// 	rotate(&lists->a, RA);
// 		// 	push(lists, PA);
// 		// 	break ;
// 		// }
// 		// else if (lists->b->c < lists->a->c && lists->b->c < low)
// 		// {
// 		// 	push(lists, PA);
// 		// 	low = lists->a->c;
// 		// 	break ;
// 		// }
// 		// else if (lists->b->c > last_a->c && last_a->c == high)
// 		// {
// 		// 	push(lists, PA);
// 		// 	high = lists->a->c;
// 		// 	rotate(&lists->a, RA);
// 		// 	break ;
// 		// }
// 		// else
// 		// 	rotate(&lists->a, RA);
// 	}
// }

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
