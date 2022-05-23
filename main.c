/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:07 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/23 15:33:58 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lists_a_b	lists;
	t_node		*temp_node;
	int			i;
	int			length_list;

	i = 1;
	lists.a = ft_new_node(atoi(argv[i]));
	i++;
	while (i < argc)
	{
		temp_node = ft_new_node(atoi(argv[i]));
		ft_list_node_add_back(&lists.a, temp_node);
		i++;
	}
	ft_list_make_index_bucket(&lists.a);
	length_list = ft_list_size(lists.a);
	if (length_list == 2)
		sort2(&lists.a);
	else if (length_list == 3)
		sort3(&lists.a);
	else if (length_list == 4)
		sort4(&lists);
	else if (length_list == 5)
		sort5(&lists);
	else if (length_list > 5)
		bucketsort(&lists);
	return (0);
}
