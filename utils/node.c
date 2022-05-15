/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:35:51 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/15 17:56:13 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_new_node(int c)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof (*new_node));
	if (!(new_node))
		return (NULL);
	new_node->c = c;
	new_node->n = NULL;
	new_node->p = NULL;
	return (new_node);
}

void	ft_node_add_back(t_node **node_lst, t_node *new_node)
{
	t_node	*current;

	if (*node_lst == NULL)
	{
		*node_lst = new_node;
		return ;
	}
	current = *node_lst;
	while (current->n != NULL)
		current = current->n;
	current->n = new_node;
	new_node->p = current;
}

int	ft_node_list_size(t_node *lst)
{
	int		i;
	t_node	*current;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		i++;
		current = current->n;
	}
	return (i);
}

t_node	*ft_last_node(t_node **list)
{
	t_node	*current;

	current = *list;
	while (current->n != NULL)
		current = current->n;
	return (current);
}

// void	ft_node_iter(t_node *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->c);
// 		lst = lst->n;
// 	}
// }
