/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:49:37 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/17 17:33:53 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	bucketsort(t_lists_a_b *lists)
{
	int	length;
	int	buck_limit;
	t_node	*temp;


	temp = lists->a;
	length = ft_list_size(lists->a);
	buck_limit = 0;
	if (length < 100)
		buck_limit = (length + 1) / 5;
	printf("Buck lim= %d\n", buck_limit);
	while (length > 0)
	{
		if (lists->a->i < buck_limit)
			push(lists, PB);
		rotate(&lists->a, RA);
		length--;
	}

}

// void	sort_index(t_lists_a_b *lists)
// {

// }