/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:06:03 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/11 12:43:40 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

// SWAP LIST_A OR LIST_B, SA, SB, SS
void	swap_top(t_node **list_a, char *op)
{
	t_node	*temp2;
	t_node	*temp3;
	int		len;

	len = ft_node_list_size(*list_a);
	if (len < 2)
		return ;
	temp2 = (*(list_a))->next;
	temp3 = temp2->next;
	if (len > 2)
	{
		temp3->previous = *list_a;
		(*(list_a))->next = temp3;
	}
	else
		(*(list_a))->next = NULL;
	(*(list_a))->previous = temp2;
	temp2->next = *list_a;
	temp2->previous = NULL;
	*list_a = temp2;

	print_operation(op);

}

void	push_top(t_node **list_from, t_node **list_to, char *op)
{
	t_node	*temp_from;
	t_node	*temp_to;
	int		len;

	temp_from = *list_from;
	temp_to = *list_to;
	len = ft_node_list_size(*list_from);
	if (len < 1)
		return ;
	else if (len > 1)
	{
		(*list_from)->next->previous = NULL;
		*list_from = (*list_from)->next;
		if (*list_to == NULL)
		{
			*list_to = temp_from;
			(*list_to)->next = NULL;
		}
		else
		{
			*list_to = temp_from;
			temp_to->previous = *list_to;
			(*list_to)->next = temp_to;
		}
	}
	else
	{
		*list_from = NULL;
		if (*list_to == NULL)
			*list_to = temp_from;
		else
		{
			*list_to = temp_from;
			temp_to->previous = *list_to;
			(*list_to)->next = temp_to;
		}
	}
	print_operation(op);
}
