/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:02:50 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/15 18:11:30 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

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

static void	sort5_h(t_lists_a_b *lists, int high, int low, t_node *last_a)
{
	while (1)
	{
		last_a = ft_last_node(&lists->a);
		if (lists->b->c > lists->a->c && lists->b->c < lists->a->n->c)
		{
			rotate(&lists->a, RA);
			push(lists, PA);
			break ;
		}
		else if (lists->b->c < lists->a->c && lists->b->c < low)
		{
			push(lists, PA);
			low = lists->a->c;
			break ;
		}
		else if (lists->b->c > last_a->c && last_a->c == high)
		{
			push(lists, PA);
			high = lists->a->c;
			rotate(&lists->a, RA);
			break ;
		}
		else
			rotate(&lists->a, RA);
	}
}

void	sort5(t_lists_a_b *lists)
{
	t_node	*last_a;
	int		len;
	int		low;
	int		high;

	len = ft_node_list_size(lists->a);
	last_a = ft_last_node(&lists->a);
	if (len > 3)
		push(lists, PB);
	if (len > 4)
		push(lists, PB);
	sort3(&lists->a);
	low = lists->a->c;
	high = lists->a->n->n->c;
	while (lists->b)
		sort5_h(lists, high, low, last_a);
	last_a = ft_last_node(&lists->a);
	while (lists->a->c > last_a->c)
	{
		last_a = last_a->p;
		r_rotate(&lists->a, RRA);
	}
}

				// printf("lists.b=%d\n", lists->b->c);
				// printf("lists.a=%d\n", lists->a->c);
				// printf("last.a=%d\n", last_a->c);
				// printf("high=%d\n", high);
				// status_nodes(&lists->a, &lists->b);
			// printf("lists.b=%d\n", lists->b->c);
			// printf("lists.a=%d\n", lists->a->c);
			// printf("last.a=%d\n", last_a->c);
		// printf("last.a=%d\n", last_a->c);
		// printf("last.a=%d\n", last_a->p->c);
		// printf("push a\n");
			// printf("temp_b=%d\n", temp_b->c);
			// printf("last_a=%d\n", last_a->c);