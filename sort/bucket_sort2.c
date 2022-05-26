/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:06:31 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 12:12:48 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

static int	if_list_a_is_bigger(t_lists_a_b *lists, t_node *last_b,
int *checker, int i)
{
	if (lists->a->i > last_b->i)
	{
		if (last_b->i > lists->b->i)//(i > 0)
		{
			r_rotate(&lists->b, RRB);
			i--;
		}
		else
		{
			*checker = -1;
			return (i);
		}
	}
	else
	{
		*checker = -1;
		return (i);
	}
	// *checker = -1;
	return (i);
}

static int	find_spot_to_insert_b_2(t_lists_a_b *lists, int i, int *checker, int amount_pushed)
{
	t_node	*last_b;

	last_b = ft_list_find_last_node(&lists->b);
	if (lists->a->i > lists->b->i)
		i = if_list_a_is_bigger(lists, last_b, checker, i);
	else if (lists->a->i < lists->b->i)
	{
		if (amount_pushed - i <= 0)
		{
			*checker = -1;
			return (i);
		}
		// else if (lists->a->i )
		// else if (lists->b->i < last_b->i)
		// {
		// 	r_rotate(&lists->b, RRB);
		// 	i--;
		// 	return (i);
		// }
		// else if (lists->b->i > last_b->i && i < 0)
		// {
		// 	*checker = -1;
		// 	return (i);
		// }
		else
		{
			rotate(&lists->b, RB);
			i++;
			return (i);
		}
		// if (lists->a->i < last_b->i && last_b->i < lists->b->i)
		// {
		// 	*checker = -1;
		// 	return (i);
		// }
		// else
		// {
		// }
	}
	return (i);
}

int	find_spot_to_insert_in_b(t_lists_a_b *lists, int i, int amount_pushed)
{
	int	len;
	int	*checker;

	checker = malloc(sizeof(int));
	*checker = 1;
	if (lists->b == NULL || lists->b->n == NULL || lists->b->n->n == NULL)
		return (i);
	len = ft_list_size(lists->b);
	while (len > i && *checker == 1)
	{
		i = find_spot_to_insert_b_2(lists, i, checker, amount_pushed);
	}
	free(checker);
	return (i);
}
//---------------------------

void	push_whole_list_to_a(t_lists_a_b *lists)
{
	while (lists->b)
		push(lists, PA);
}

void	sort_b_hi_to_lo(t_node **list_b)
{
	t_node	*last_b;

	last_b = ft_list_find_last_node(list_b);
	while ((*list_b)->i < last_b->i)
	{
		r_rotate(list_b, RRB);
		last_b = ft_list_find_last_node(list_b);
	}
}