/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:16:25 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/26 14:18:49 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

void	print_operation(char *operation)
{
	write(1, operation, ft_strlen(operation));
}

void	stupid_move(char *op)
{
	print_operation(op);
	write(1, "STUPID MOVE\n", 12);
}
