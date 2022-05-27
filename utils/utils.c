/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:33:01 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/27 12:33:25 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	check_dubble_values(t_node **list_a)
{
	int		count;
	t_node	*temp;
	t_node	*temp1;

	count = 0;
	temp = *list_a;
	while (temp != NULL)
	{
		temp1 = *list_a;
		count = 0;
		while (temp1 != NULL)
		{
			if (temp->c - temp1->c == 0)
				count++;
			temp1 = temp1->n;
		}
		if (count > 1)
		{
			error_mgs();
		}
		temp = temp->n;
	}
}
