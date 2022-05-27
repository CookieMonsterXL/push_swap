/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:07 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/27 15:38:38 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

static int	isdigit2(int c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

static void	check_nummbers(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (!(isdigit2(argv[i][k])))
				error_mgs();
			k++;
		}
		i++;
	}
}

static int	make_int_and_check_max_min(char *str)
{
	int	num;

	num = ft_atoi(str);
	if (ft_strncmp(str, "0\0", 2) != 0 && num == 0)
		error_mgs();
	return (num);
}

static t_lists_a_b	*make_list(int argc, char **argv)
{
	int			i;
	t_node		*temp_node;
	t_lists_a_b	*lists;
	int			num;

	lists = malloc(sizeof(t_lists_a_b));
	if (lists == NULL)
		exit(0);
	lists->a = NULL;
	lists->b = NULL;
	i = 1;
	num = make_int_and_check_max_min(argv[i]);
	lists->a = ft_new_node(num);
	i++;
	while (i < argc)
	{
		num = make_int_and_check_max_min(argv[i]);
		temp_node = ft_new_node(num);
		ft_list_node_add_back(&lists->a, temp_node);
		i++;
	}
	check_dubble_values(&lists->a);
	return (lists);
}

int	main(int argc, char **argv)
{
	t_lists_a_b	*lists;
	int			length_list;

	if (argc < 2)
		exit(1);
	check_nummbers(argv);
	lists = make_list(argc, argv);
	if (ft_list_check_sorted(&lists->a))
		exit(0);
	list_make_index_bucket(&lists->a);
	length_list = ft_list_size(lists->a);
	if (length_list == 2)
		sort2(&lists->a);
	else if (length_list == 3)
		sort3(&lists->a);
	else if (length_list == 4)
		sort4(lists);
	else if (length_list == 5)
		sort5(lists);
	else if (length_list > 5)
		bucketsort(lists);
	exit(0);
	return (0);
}

	// system("leaks push_swap");
	//status_nodes(&lists->a, &lists->b);