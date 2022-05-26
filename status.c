/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:56:23 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 14:47:54 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"
#include <stdio.h>

void	print_b(t_node **head_node_b)
{
	t_node	*temp;
	int		i;

	temp = *head_node_b;
	i = ft_list_size(temp);
	printf("list B\n");
	printf("length: %d\n", i);
	if (temp)
	{
		while (temp->n)
		{
			printf("\tvalue= %d index=%d bucket-N=%d\n",
				temp->c, temp->i, temp->b_n);
			if (temp->n != NULL)
				temp = temp->n;
		}
		if (temp)
			printf("\tvalue= %d index=%d bucket-N=%d\n",
				temp->c, temp->i, temp->b_n);
	}
}

void	status_nodes(t_node **head_node_a, t_node **head_node_b)
{
	int		i;
	t_node	*temp;

	temp = *head_node_a;
	i = ft_list_size(temp);
	printf("list A\n");
	printf("length: %d\n", i);

	if (temp != NULL)
	{
		while (temp && temp->n)
		{
			printf("\tvalue= %d index=%d bucket-N=%d\n",
				temp->c, temp->i, temp->b_n);
			if (temp->n != NULL)
				temp = temp->n;
		}
		if (temp)
			printf("\tvalue= %d index=%d bucket-N=%d\n",
				temp->c, temp->i, temp->b_n);
	}
	print_b(head_node_b);
}
