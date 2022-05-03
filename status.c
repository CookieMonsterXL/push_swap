#include <stdio.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:56:23 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/03 12:59:56 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

void	status_nodes(t_node *head_node_a)
{
	int	i;

	i = ft_node_list_size(head_node_a);
	printf("list A\n");
	printf("length: %d\n", i);
	while (head_node_a->next)
	{
		printf("value= %d\n", head_node_a->content);
		if (head_node_a->next != NULL)
			head_node_a = head_node_a->next;
	}
	printf("value= %d\n", head_node_a->content);
}
