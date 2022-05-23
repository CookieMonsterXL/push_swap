/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:38:31 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/23 15:46:00 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

// PUSH TO A OR B, INSERT PA or PB
static void	push_node_to_other_list(t_node **list_from, t_node **list_to)
{
	t_node	*temp_from;
	t_node	*temp_to;

	temp_from = *list_from;
	temp_to = *list_to;
	(*list_from)->n->p = NULL;
	*list_from = (*list_from)->n;
	if (*list_to == NULL)
	{
		*list_to = temp_from;
		(*list_to)->n = NULL;
	}
	else
	{
		*list_to = temp_from;
		(*list_to)->n = temp_to;
		(*list_to)->n->p = *list_to;
	}
}

static void	push_last_node_to_other_list(t_node **list_from, t_node **list_to)
{
	t_node	*temp_from;
	t_node	*temp_to;

	temp_from = *list_from;
	temp_to = *list_to;
	*list_from = NULL;
	if (*list_to == NULL)
		*list_to = temp_from;
	else
	{
		*list_to = temp_from;
		temp_to->p = *list_to;
		(*list_to)->n = temp_to;
	}
}

void	push(t_lists_a_b *lists, char *op)
{
	int		len;

	if (op == PB)
		len = ft_list_size(lists->a);
	else
		len = ft_list_size(lists->b);
	if (len < 1)
		return (stupid_move(op));
	else if (len >= 2 && op == PB)
		push_node_to_other_list(&lists->a, &lists->b);
	else if (len >= 2 && op == PA)
		push_node_to_other_list(&lists->b, &lists->a);
	else if (len == 1 && op == PB)
		push_last_node_to_other_list(&lists->a, &lists->b);
	else if (len == 1 && op == PA)
		push_last_node_to_other_list(&lists->b, &lists->a);
	print_operation(op);
}
