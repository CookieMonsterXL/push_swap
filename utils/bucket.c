/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:59:13 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/23 18:59:14 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

//Calculate the amount in each bucket, 
//and puts the value in a_i_b (amount in this bucket)
void	do_bucket_stuff(t_node **list_a, int amount_of_buckets)
{
	int		*arr;
	int		i;
	t_node	*current;

	arr = ft_calloc(amount_of_buckets, sizeof(int));
	i = 0;
	while (amount_of_buckets > i)
	{
		arr[i] = 0;
		i++;
	}
	current = *list_a;
	i = 0;
	while (current)
	{
		(arr[current->b_n])++;
		current = current->n;
	}
	i = 0;
	current = *list_a;
	while (current)
	{
		current->a_i_b = arr[current->b_n];
		current = current->n;
	}
	free(arr);
}

int	find_amount_of_buckets(int length_list)
{
	if (length_list < 10)
		return (1);
	else if (length_list >= 10 && length_list <= 50)
		return (2);
	else if (length_list > 50 && length_list <= 250)
		return (6);
	else if (length_list > 250 && length_list <= 500)
		return (11);
	return (15);
}