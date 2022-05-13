/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:35:51 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/13 16:59:54 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_new_node(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof (*new_node));
	if (!(new_node))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->previous = NULL;
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
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->previous = current;
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
		current = current->next;
	}
	return (i);
}

t_node	*ft_last_node(t_node **list)
{
	t_node	*current;

	current = *list;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

// void	ft_node_iter(t_node *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }
