/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:49:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 12:25:50 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

static int	find_low(t_node **list_a)
{
	t_node	*current;
	int		lo;

	current = *list_a;
	lo = INT_MAX;
	while (current)
	{
		if (current->c < lo && current->i < 0)
			lo = current->c;
		current = current->n;
	}
	return (lo);
}

static int	need_indexing(t_node **list_a)
{
	t_node	*current;
	int		need_indexing;

	need_indexing = 0;
	current = *list_a;
	while (current)
	{
		if (current->i < 0)
			need_indexing++;
		current = current->n;
	}
	return (need_indexing);
}

void	do_indexing(t_node **list_a, int buckets, int size, int range)
{
	t_node	*current;
	int		i;
	int		lo;

	i = 0;
	current = *list_a;
	while (need_indexing(list_a))
	{
		lo = find_low(list_a);
		while (current)
		{
			if (current->c == lo)
			{
				current->i = i;
				current->b_n = current->i / range;
				current->a_b = buckets;
				current->t_l_s = size;
			}
			current = current->n;
		}
		i++;
		current = *list_a;
	}
}

void	list_make_index_bucket(t_node **list_a)
{
	int		buckets;
	int		size;
	int		range;

	size = ft_list_size(*list_a);
	buckets = find_amount_of_buckets(size);
	range = (size) / buckets;
	do_indexing(list_a, buckets, size, range + 1);
	do_bucket_stuff(list_a, buckets);
}
