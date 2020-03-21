/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:59:54 by rick              #+#    #+#             */
/*   Updated: 2020/03/21 16:00:46 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	list_checkduplicate(t_list_stack *list)
{
	int		temp;
	int		k;
	t_stack	*stack;
	t_stack	*iterate;

	k = 0;
	stack = list->head;
	iterate = list->head;
	while (iterate != NULL)
	{
		temp = iterate->num;
		while (stack != NULL)
		{
			if (stack->num == temp)
				k++;
			if (k == 2)
				return (false);
			stack = stack->next;
		}
		iterate = iterate->next;
		stack = list->head;
		k = 0;
	}
	return (true);
}

int		input_check_number(char *array)
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