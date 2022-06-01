/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:33:01 by tbouma            #+#    #+#             */
/*   Updated: 2022/06/01 11:46:27 by tbouma           ###   ########.fr       */
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

static int	atoi_h(long long num_l, int minplus, int *error)
{
	num_l *= minplus;
	if (num_l < INT_MIN || num_l > INT_MAX)
		*error = 1;
	return (num_l);
}

int	ft_atoi_minmax_check(const char *str, int *error)
{
	int			i;
	int			num;
	long long	num_l;
	int			minplus;

	i = 0;
	num_l = 0;
	minplus = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minplus = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num_l *= 10;
		num_l += str[i] - 48;
		i++;
	}
	num = atoi_h(num_l, minplus, error);
	return (num);
}
