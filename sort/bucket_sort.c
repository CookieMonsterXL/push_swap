/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:06:44 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/20 19:41:26 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	push_whole_list_to_a(t_lists_a_b *lists)
{
	// printf("PUSH ALL BACK TO A. FINISH!!!!!!!!!!!!!!!!!!!!!\n");
	while (lists->b)
		push(lists, PA);
}

void	sort_b_hi_to_lo(t_node **list_b)
{
		// printf("SORT B BACK TO NORMAL\n");
	t_node	*last_b;

	last_b = ft_list_find_last_node(list_b);
	while ((*list_b)->i < last_b->i)
	{
		r_rotate(list_b, RRB);
		last_b = ft_list_find_last_node(list_b);
	}
}

		// printf("TEst11\n");
int	find_spot_to_insert_in_b(t_lists_a_b *lists, int i)
{
	// printf("FINDING RIGHT INDEX B\n");

	t_node	*last_b;

	if (lists->b == NULL || lists->b->n == NULL)
		return i;
	while (ft_list_size(lists->b) > i)//does not make sense?????
	{
		last_b = ft_list_find_last_node(&lists->b);

		if (lists->a->i > lists->b->i)
		{
			if (lists->a->i > last_b->i)
			{
				if (i > 0)
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
		else if (lists->a->i < lists->b->i) //list_a is greater and list b in incurect order.
			{
				rotate(&lists->b, RB);
				i++;
			}
	}
	return i;
}

int	find_next_in_a(t_node **list_a, int current_bucket)
{
	// printf("FINGING RIGHT INDEX A\n");
	int	i;

	i = 0;
	while (i < ft_list_size(*list_a)) //makes sense???
	{
		if ((*list_a)->b_n == current_bucket)
			return ((*list_a)->a_i_b);
		else
			rotate(list_a, RA);
		i++;
	}
	return ((*list_a)->a_i_b);
}

void	push_bucket(t_lists_a_b *lists, int bucket_number)
{
	// printf("PUSHING BUCKET\n");
	int	i;
	int b;
	int amount_in_bucket;

	i = 0;
	b = 0;
	amount_in_bucket = find_next_in_a(&lists->a, bucket_number);
	while (amount_in_bucket > i)
	{
		find_next_in_a(&lists->a, bucket_number);
		b = find_spot_to_insert_in_b(lists, b);
		push(lists, PB);
		i++;
	}
}

void	bucketsort(t_lists_a_b *lists)
{
	// printf("BUCKETSORT\n");
	int			length_list;
	int			bucket_number;
	int			amount_of_buckets;

	length_list = ft_list_size(lists->a);
	amount_of_buckets = lists->a->a_b;
	bucket_number = 0;

	while (bucket_number < amount_of_buckets)
	{
		push_bucket(lists, bucket_number);
		sort_b_hi_to_lo(&lists->b);
		bucket_number++;
		// printf("BUCKET DONE\n");
	}
	push_whole_list_to_a(lists);
}
