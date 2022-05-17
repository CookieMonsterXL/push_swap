/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:49:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/17 16:05:02 by tbouma           ###   ########.fr       */
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

static int	find_high(t_node **list_a)
{
	t_node	*current;
	int		hi;

	current = *list_a;
	hi = INT_MIN;
	while (current)
	{
		if (current->c > hi && current->i < 0)
			hi = current->c;
		current = current->n;
	}
	return (hi);
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

void	ft_list_make_index(t_node **list_a)
{
	int		i;
	int		lo;
	int		hi;
	int		size;
	t_node	*current;

	i = 0;
	current = *list_a;
	size = ft_list_size(current);
	while (need_indexing(list_a))
	{
		lo = find_low(list_a);
		hi = find_high(list_a);
		while (current)
		{
			if (current->c == lo)
				current->i = i;
			if (current->c == hi)
				current->i = size - 1 - i;
			current = current->n;
		}
		i++;
		current = *list_a;
	}
}
		// printf("hi= %d, lo=%d\n", hi, lo); //DEBUG
