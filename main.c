/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:07 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 12:15:30 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

static void	make_list(t_lists_a_b *lists, int argc, char **argv)
{
	int		i;
	t_node	*temp_node;

	i = 1;
	lists->a = ft_new_node(atoi(argv[i]));
	i++;
	while (i < argc)
	{
		temp_node = ft_new_node(atoi(argv[i]));
		ft_list_node_add_back(&lists->a, temp_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_lists_a_b	lists;
	int			length_list;

	make_list(&lists, argc, argv);
	list_make_index_bucket(&lists.a);
	// status_nodes(&lists.a, &lists.b);
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
	// status_nodes(&lists.a, &lists.b);
	return (0);
}
