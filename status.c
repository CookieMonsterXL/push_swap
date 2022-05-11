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

void	status_nodes(t_node **head_node_a, t_node **head_node_b)
{
	int		i;
	t_node	*temp;
// 	LIST A
	temp = *head_node_a;
	i = ft_node_list_size(temp);
	printf("list A\n");
	printf("length: %d\n", i);
	while (temp->next)
	{
		printf("\tvalue= %d\n", temp->content);
		if (temp->next != NULL)
			temp = temp->next;
	}
	if (temp)
		printf("\tvalue= %d\n", temp->content);
// 	LIST B
	temp = *head_node_b;
	i = ft_node_list_size(temp);
	printf("list B\n");
	printf("length: %d\n", i);
	if (temp)
	{
		while (temp->next)
		{
			printf("\tvalue= %d\n", temp->content);
			if (temp->next != NULL)
				temp = temp->next;
		}
		if (temp)
			printf("\tvalue= %d\n", temp->content);
	}
}
