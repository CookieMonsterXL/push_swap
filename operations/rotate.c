/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:22:33 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/13 17:30:11 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	rotate(t_node **list, char *op)
{
	t_node	*temp;
	t_node	*last;
	int		len;

	temp = *list;
	len = ft_node_list_size(*list);
	if (len < 2)
		return (stupid_move(op));
	last = ft_last_node(list);
	*list = (*list)->next;
	(*list)->previous = NULL;
	last->next = temp;
	temp->previous = last;
	temp->next = NULL;
	if (op)
		print_operation(op);
}

void	rotate_rr(t_lists_a_b *lists)
{
	rotate(&lists->a, NULL);
	rotate(&lists->b, NULL);
	print_operation(RR);
}
// seg fault in r _rotate rotate gaat goed
void	r_rotate(t_node **list, char *op)
{
	t_node	*temp;
	t_node	*last;
	int		len;

	temp = *list;
	len = ft_node_list_size(*list);
	if (len < 2)
		return (stupid_move(op));
	last = ft_last_node(list);
	*list = last;
	(*list)->previous = NULL;
	(*list)->next = temp;
	temp->previous = *list;
	last->previous->next = NULL;
	// temp->previous = last;
	// temp->next = NULL;
	if (op)
		print_operation(op);
}

