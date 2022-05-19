/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:06:44 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/19 19:28:04 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	sort_b_hi_to_lo(t_node **list_b)
{
		printf("SORT B BACK TO NORMAL\n");
	t_node	*last_b;

	last_b = ft_list_find_last_node(list_b);
	while ((*list_b)->i < last_b->i)
	{
		r_rotate(list_b, RRB);
		last_b = ft_list_find_last_node(list_b);
	}
}

		// printf("TEst11\n");
int	find_spot_to_insert_in_b(t_lists_a_b *lists, t_bucket *bucket, int i)
{
	printf("FINGING RIGHT INDEX B\n");

	t_node	*last_b;

	bucket->amount_buckets = bucket->amount_buckets;
	//i = 0;
	if (lists->b == NULL || lists->b->n == NULL)
		return i;
	while (ft_list_size(lists->b) >= i)//does not make sense
	{
		last_b = ft_list_find_last_node(&lists->b);
		if (lists->b->i < lists->a->i)//&& last_b->i < lists->a->i
		{
			if (last_b->i < lists->a->i)
			{
				if (i > 0)//last_b->i < last_b->p->i &&
				{
					r_rotate(&lists->b, RRB);
					i--;
				}
				else
					return i;
			}
			else
				return i;
		}

		// else if (lists->b->i < lists->a->i )//list_a is between last_b and list_b && last_b->i > lists->a->i
		// 	return ;
		else if (lists->b->i > lists->a->i) //list_a is greater and list b in incurect order.
			{
				rotate(&lists->b, RB);
				i++;
			}
		// else if (last_b->i > lists->a->i && lists->b->i > lists->a->i && last_b->i > lists->b->i) //list_a is smaller then both 0 > 32   34 > 32
		// 	rotate(&lists->b, RB);
		// else if (last_b->i > lists->a->i && last_b->i > lists->b->i) //list_a is smaller then both 0 > 32   34 > 32
		// 	r_rotate(&lists->b, RRB);
	}
		printf("FAIL\n");
		return i;
}

void	find_next_in_a(t_node **list_a, t_bucket *bucket)
{
	printf("FINGING RIGHT INDEX A\n");
	int	i;

	i = 0;
	while (i < ft_list_size(*list_a))
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
	printf("PUSHING BUCKET\n");
	int	i;
	int b;

	i = 0;
	b = 0;
	while (bucket->limit_hi - bucket->limit_lo >= i)
	{
		find_next_in_a(&lists->a, bucket);
		b += find_spot_to_insert_in_b(lists, bucket, b);
		push(lists, PB);
		i++;
	}

		// printf("TEst10\n");
	//sort_b_hi_to_lo(lists->b);
}

void	make_next_bucket(t_bucket *bucket, int length_list)
{
	printf("MAKING BUCKET\n");
	bucket->number++;
	if (bucket->number == 1)
	{
		bucket->limit_lo = 0;
	}
	else
	{
		bucket->limit_lo = bucket->limit_hi + 1;
	}
	if (bucket->number == bucket->amount_buckets)
	{
		bucket->limit_hi = length_list - 1;
	}
	else
	{
		bucket->limit_hi = length_list / bucket->amount_buckets + bucket->limit_lo;
	}
}

int	find_amount_of_buckets(int length_list)
{
	printf("FINDING AMOUNT OF BUCKETS\n");
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
	printf("BUCKETSORT\n");
	int			length_list;
	t_bucket	bucket;

	length_list = ft_list_size(lists->a);
	bucket.number = 0;
	bucket.amount_buckets = find_amount_of_buckets(length_list);
	make_next_bucket(&bucket, length_list);
	while (bucket.number <= bucket.amount_buckets)
	{
		push_bucket(lists, &bucket);
		sort_b_hi_to_lo(&lists->b);
		printf("BUCKET DONE\n");
		status_nodes(&lists->a, &lists->b);
		make_next_bucket(&bucket, length_list);
	}
	// sort_last_bucket();
	// push_whole_list_to_a();

}

		// printf("bucket amount%d\n", bucket.amount_buckets);
		// printf("bucket hi%d\n", bucket.limit_hi);
		// printf("bucket lo%d\n", bucket.limit_lo);
		// printf("bucket nr%d\n", bucket.number);
	// printf("bucket amount%d\n", bucket.amount_buckets);
	// printf("bucket hi%d\n", bucket.limit_hi);
	// printf("bucket lo%d\n", bucket.limit_lo);
	// printf("bucket nr%d\n", bucket.number);