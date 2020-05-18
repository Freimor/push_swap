/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:59:54 by rick              #+#    #+#             */
/*   Updated: 2020/04/07 15:07:31 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*t_bool	check_listfordup(t_list_stack *list, int ac, char **arg)
{
	int		i;
	char	**new;

	i = 0;
	if (ac == 2)
	{
		new = ft_strsplit(arg[1], ' ');
		while (new[i] != NULL)
		{
			form_first_list(list, ft_atoi(new[i]));
			free(new[i]);
			i++;
		}
		free(new);
	}
	else if (ac > 2)
	{
		while (++i < ac)
			form_first_list(list, ft_atoi(arg[i]));
	}
	if (list_checkduplicate(list) == false)
	{
		ft_putstr("Error dup\n");
		return (false);
	}
	return (true);
}*/

t_bool	check_listfordup(t_list_stack *list, int ac, char **arg)	/* CHECKED */
{
	int		i;
	int		j;
	int		k;
	t_bool	control;
	char	**new;

	i = 1;
	while (i < ac)
	{
		control = false;
		j = 0;
		while (arg[i][j] != '\0')
		{
			if (arg[i][j] == ' ')
			{
				k = 0;
				control = true;
				new = ft_strsplit(arg[i], ' ');
				while (new[k] != NULL)
				{
					form_first_list(list, ft_atoi(new[k]));
					free(new[k]);
					k++;
				}
				free(new);
				break ;
			}
			j++;
		}
		if (control == false)
			form_first_list(list, ft_atoi(arg[i]));
		i++;
	}
	if (list_checkduplicate(list) == false)
		return (false);
	return (true);
}

static t_bool	input_check_onearg(char *str)
{
	int		i;
	char	**new;
	t_bool	flag;
	t_bool	ch;

	i = 0;
	ch = false;
	flag = true;
	if (str[0] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			new = ft_strsplit(str, ' ');
			i = 0;
			ch = true;
			while (new[i] != NULL)
			{
				if (new[i][0] == '\0')
					flag = false;
				if (input_check_number(new[i]) == false)
					flag = false;
				free(new[i]);
				i++;
			}
			free(new);
			break ;
		}
		i++;
	}
	if (ch == false)
		flag = input_check_number(str);
	return (flag);
}

/*t_bool	input_checker(int ac, char **arg)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (false);
	else if (ac == 2)
		return (input_check_onearg(arg[i]));
	else if (ac > 2)
	{
		while (i < ac)
		{
			if (arg[i][0] == '\0')
				return (false);
			if (input_check_number(arg[i]) == false)
				return (false);
			i++;
		}
	}
	return (true);
}*/

t_bool	input_checker(int ac, char **arg)	/* CHECKED */
{
	int	i;

	i = 1;
	if (ac < 2)
		return (false);
	else
	{
		while (i < ac)
		{
			if (input_check_onearg(arg[i]) == false)
				return (false);
			i++;
		}
	}
	return (true);
}

int		input_check_number(char *array)	/* CHECKED */
{
	int	i;

	i = 0;
	if (ft_strequ(array, "2147483648") == true || ft_strequ(array, "-2147483649"))
			return (false);
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