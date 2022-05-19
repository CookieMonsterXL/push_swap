/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:06:44 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/19 11:04:32 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	sort_b_hi_to_lo(t_node *list_b)
{
	t_node	*last_b;

	last_b = ft_list_find_last_node(&list_b);
	while (list_b->i < last_b->i)
		r_rotate(&list_b, RRB);
}

void	find_spot_to_insert_in_b(t_lists_a_b *lists)
{
	t_node	*last_b;

	while (1)
	{
		last_b = ft_list_find_last_node(&lists->b);
		if (last_b->i < lists->a->i && lists->b->i < lists->a->i) //list_a is greater and list_b is good
			return ;
		else if (last_b->i > lists->a->i && lists->b->i > lists->a->i) //list_a is smaller then both
			rotate(&lists->b, RB);
		else if (lists->b->i < lists->a->i && last_b->i > lists->a->i)//list_a is between last_b and list_b
			return ;
		else if (lists->b->i > lists->a->i) //list_a is greater and list b in incurect order.
			r_rotate(&lists->b, RRB);
	}
}

void	find_next_in_a(t_node **list_a, t_bucket *bucket)
{
	int	i;

	i = 0;
	while (i <= ft_list_size(*list_a))
	{
		if ((*list_a)->i >= bucket->limit_lo && (*list_a)->i <= bucket->limit_hi)
			return ;
		else
			rotate(list_a, RA);
		i++;
	}
}

void	push_bucket(t_lists_a_b *lists, t_bucket *bucket)
{
	int	i;

	i = 0;
	while (bucket->limit_hi - bucket->limit_lo >= i)
	{
		find_next_in_a(&lists->a, bucket);
		find_spot_to_insert_in_b(lists);
		push(lists, PB);
		i++;
	}

	//sort_b_hi_to_lo(lists->b);
}

void	make_next_bucket(t_bucket *bucket, int length_list)
{
	bucket->number++;
	if (bucket->number == 1)
		bucket->limit_lo = 0;
	else
		bucket->limit_lo = bucket->limit_hi + 1;
	if (bucket->number == bucket->amount_buckets)
		bucket->limit_hi = length_list;
	else
	bucket->limit_hi = length_list / bucket->amount_buckets + bucket->limit_lo;
}

int	find_amount_of_buckets(int length_list)
{
	if (length_list < 10)
		return (1);
	else if (length_list >= 10 && length_list <= 50)
		return (length_list / 10);
	else if (length_list > 50 && length_list <= 250)
		return (5);
	else if (length_list > 250 && length_list <= 500)
		return (length_list / 50);
	return (10);
}

void	bucketsort(t_lists_a_b *lists)
{
	int			length_list;
	t_bucket	bucket;

	length_list = ft_list_size(lists->a);
	bucket.number = 0;
	bucket.amount_buckets = find_amount_of_buckets(length_list);

	while (1)
	{
		make_next_bucket(&bucket, length_list);
		push_bucket(lists, &bucket);
		sort_b_hi_to_lo(lists->b);
	}
	// sort_last_bucket();
	// push_whole_list_to_a();

}
