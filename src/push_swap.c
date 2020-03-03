/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/03/02 15:44:27 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list_stack	*form_first_list(t_list_stack *list, int num)
{
	t_stack *stack;

	if (list == NULL)
	{
		list = (t_list_stack *)malloc(sizeof(t_list_stack));
		list->head = NULL;
	}
	if (list->head == NULL)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		stack->num = num;
		stack->next = NULL;
		stack->index = -1;
		stack->keep_in = false;
		list->head = stack;
	}
	else
	{
		stack = list->head;
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		stack->next->num = num;
		stack->next->next = NULL;
		stack->next->index = -1;
	}
	return(list);
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

int	main(int ac, char **arg)
{
	t_list_stack	*list;
	t_list_stack	*new_list;
	int	i;

	i = 1;
	list = NULL;
	if (ac < 2)
	{
		ft_putstr("Error input\n");
		return (0);
	}
	while (i < ac)
	{
		if (input_check_number(arg[i]) == false)
		{
			ft_putstr("Error on args\n");
			return(0);
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		list = form_first_list(list, ft_atoi(arg[i]));
		i++;
	}
	if (list_checkduplicate(list) == false)
	{
		ft_putstr("Error dup\n");
		return (0);
	}
	markup_big(list);
	print_list(list, true, true);
	solve_1(list);
	return (0);
}