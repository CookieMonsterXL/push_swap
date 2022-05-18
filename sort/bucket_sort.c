/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:49:37 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/18 15:49:50 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	rotate_b_back(t_node **list_b)
{
	t_node	*last;

	while (1)
	{
		last = ft_list_find_last_node(list_b);
		if ((*list_b)->i < last->i)
			r_rotate(list_b, RRB);
		else
			break ;
	}
}

void	push_bucket(int limit_lo, int limit_hi, t_lists_a_b *lists)
{
	int	i;
	//t_node	*current;
	t_node	*last;

	i = 1;
	if (!lists->b)
		push(lists, PB);
	while (limit_hi - limit_lo >= i)
	{
		//current = lists->a;
		last = ft_list_find_last_node(&lists->b);
		if (lists->a->i >= limit_lo && lists->a->i <= limit_hi)
		{
			if (((lists->b->i < lists->a->i) && last->i < lists->a->i) || ft_list_size(lists->b) == 1)
			{
				push(lists, PB);
				i++;
				continue ;
			}
			else
			{
				rotate(&lists->b, RB);
				continue ;
			}
		}
		printf("limith=%d limitl=%d\n", limit_hi, limit_lo);
		rotate(&lists->a, RA);
	}
	rotate_b_back(&lists->b);
}

void	make_next_bucket(int *limit_lo, int *limit_hi, int length, int bucket_n)
{
	*limit_lo = *limit_hi + 1;
	*limit_hi = ((length + 1) / bucket_n) + *limit_lo;
}

void	bucketsort(t_lists_a_b *lists)
{
	int		length_list;
	int		limit_hi;
	int		limit_lo;
	int		bucket_n;
	t_node	*temp;

	limit_hi = -1;
	printf("%d\n", limit_hi);
	bucket_n = 5;
	temp = lists->a;
	length_list = ft_list_size(lists->a);
	while (length_list > limit_hi)
	{
		printf("limithi=%d\n", limit_hi);
		make_next_bucket(&limit_lo, &limit_hi, length_list, bucket_n);
		push_bucket(limit_lo, limit_hi, lists);

	}

	//printf("Buck lim= %d\n", limit_hi);
	// while (length_list > 0)
	// {
	// 	if (lists->a->i < limit_hi)
	// 		push(lists, PB);
	// 	rotate(&lists->a, RA);
	// 	length_list--;
	// }

}

// void	sort_index(t_lists_a_b *lists)
// {

// }