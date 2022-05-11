#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:07 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/02 13:19:15 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_node_a;
	t_node	*head_node_b;
	t_node	*temp_node;
	int		i;

	i = 1;
	head_node_a = ft_new_node(atoi(argv[i]));
	i++;
	while (i < argc)
	{
		temp_node = ft_new_node(atoi(argv[i]));
		ft_node_add_back(&head_node_a, temp_node);
		i++;
	}

	status_nodes(&head_node_a, &head_node_b);
	swap_top(&head_node_a, SA);
	push_top(&head_node_a, &head_node_b, PB);
	push_top(&head_node_a, &head_node_b, PB);
	push_top(&head_node_b, &head_node_a, PA);
	status_nodes(&head_node_a, &head_node_b);
	return (0);
}
