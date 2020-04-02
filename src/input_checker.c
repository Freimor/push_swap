/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:59:54 by rick              #+#    #+#             */
/*   Updated: 2020/03/31 17:52:25 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	check_listfordup(t_list_stack *list, int ac, char **arg)	/* CHECKED */
{
	int	i;

	i = 0;
	while (++i < ac)
		form_first_list(list, ft_atoi(arg[i]));
	if (list_checkduplicate(list) == false)
	{
		ft_putstr("Error dup\n");
		return (false);
	}
	return (true);
}

t_bool	input_checker(int ac, char **arg)	/* CHECKED */
{
	int	i;

	i = 1;
	if (ac < 2)
	{
		ft_putstr("Error input\n");
		return (false);
	}
	while (i < ac)
	{
		if (input_check_number(arg[i]) == false)
		{
			ft_putstr("Error on args\n");
			return (false);
		}
		i++;
	}
	return (true);
}

int		input_check_number(char *array)	/* CHECKED */
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == '+' || array[i] == '-')
		{
			if (!(array[i + 1] > '0' && array[i + 1] <= '9'))
				return (false);
			if (array[i + 1] == '0')
				return (false);
		}
		else if (!(array[i] >= '0' && array[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}