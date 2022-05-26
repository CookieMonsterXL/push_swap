/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:38:10 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 12:38:58 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	swap_h(t_node *temp, t_node *temp1, t_node *temp3, int len)
{
	if (len > 2)
	{
		temp->p = temp1;
		temp->n = temp3;
		temp3->p = temp;
	}
	else if (len == 2)
	{
		temp->n = NULL;
		temp->p = temp1;
	}
}

// SWAP LIST A OR B, (SA, SB)
void	swap(t_node **list, char *op)
{
	t_node	*temp;
	t_node	*temp1;
	t_node	*temp3;
	int		len;

	temp = *list;
	temp1 = temp->n;
	len = ft_list_size(*list);
	if (len > 2)
		temp3 = temp1->n;
	if (len < 2)
		return (stupid_move(op));
	temp1->n = temp;
	temp1->p = NULL;
	swap_h(temp, temp1, temp3, len);
	*list = temp1;
	if (op)
		print_operation(op);
}

//SWAP BOTH (SS)
void	swap_ss(t_lists_a_b *lists)
{
	swap(&lists->a, NULL);
	swap(&lists->b, NULL);
	print_operation(SS);
}

	// int z = 0;
	// while (z < 3)
	// {
	// 	printf("next \t\t%p\n", temp1->n);
	// 	printf("prev \t\t%p\n", temp1->p);
	// 	printf("current \t%p\n", temp1);
	// 	printf("len = \t%d\n", len);
	// 	temp1 = temp1->n;
	// 	z++;
	// }
	// printf("next \t\t%p\n", temp1->n);
	// printf("prev \t\t%p\n", temp1->p);
	// printf("current \t%p\n", temp1);
	// printf("len = \t%d\n", len);