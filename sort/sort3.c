/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:02:50 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/15 17:47:05 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	sort3(t_node **list_a)
{
	if ((*list_a)->content > (*list_a)->next->content) //case 1,2,3
	{
		if ((*list_a)->content > (*list_a)->next->next->content) //case 2,3
		{
			if ((*list_a)->next->content > (*list_a)->next->next->content)  //case 2
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
		if ((*list_a)->content > (*list_a)->next->next->content) //case 5
			r_rotate(list_a, RRA);
		if ((*list_a)->next->content > (*list_a)->next->next->content) //case 4
		{
			swap(list_a, SA);
			rotate(list_a, RA);
		}
	}
}

void	sort5(t_lists_a_b *lists)
{
	t_node	*last_a;
	int		len;
	int		low;
	int		high;

	len = ft_node_list_size(lists->a);
	if (len > 3)
		push(lists, PB);
	if (len > 4)
		push(lists, PB);
	sort3(&lists->a);
	low = lists->a->content;
	high = lists->a->next->next->content;
	while (lists->b)
	{
		while (1)
		{
			last_a = ft_last_node(&lists->a);
			if (lists->b->content > lists->a->content && lists->b->content < lists->a->next->content)
			{
				rotate(&lists->a, RA);
				push(lists, PA);
				break ;
			}
			else if (lists->b->content < lists->a->content && lists->b->content < low)
			{
				push(lists, PA);
				low = lists->a->content;
				break ;
			}
			else if (lists->b->content > last_a->content && last_a->content == high)
			{
				push(lists, PA);
				high = lists->a->content;
				rotate(&lists->a, RA);
				break ;
			}
			else
				rotate(&lists->a, RA);
		}
	}
	last_a = ft_last_node(&lists->a);
	while (lists->a->content > last_a->content)
	{
		last_a = last_a->previous;
		r_rotate(&lists->a, RRA);
	}
}

				// printf("lists.b=%d\n", lists->b->content);
				// printf("lists.a=%d\n", lists->a->content);
				// printf("last.a=%d\n", last_a->content);
				// printf("high=%d\n", high);
				// status_nodes(&lists->a, &lists->b);
			// printf("lists.b=%d\n", lists->b->content);
			// printf("lists.a=%d\n", lists->a->content);
			// printf("last.a=%d\n", last_a->content);
		// printf("last.a=%d\n", last_a->content);
		// printf("last.a=%d\n", last_a->previous->content);
		// printf("push a\n");
			// printf("temp_b=%d\n", temp_b->content);
			// printf("last_a=%d\n", last_a->content);