/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_additionals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:06:20 by freimor           #+#    #+#             */
/*   Updated: 2020/03/21 17:04:41 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	rb_or_rrb(t_list_stack *b, int index)
{
	t_stack	*stack;
	int	a;
	int	c;

	a = 0;
	c = 0;
	stack = b->head;
	while (stack != NULL)
	{
		a++;
		if (stack->index == index)
			c = a;
		stack = stack->next;
	}
	return (a - c >= c ? true : false);
}

t_bool	check_align(t_list_stack *list, t_bool rigor)
{
	t_stack *stack;

	stack = list->head;
	if (rigor == false)
	{
		while (stack->next != NULL)
		{
			if (stack->index > stack->next->index)
				return (false);
			stack = stack->next;
		}
	}
	else
	{
		while(stack->next != NULL)
		{
			if (stack->index != stack->next->index + 1)
				return (false);
			stack = stack->next;
		}
	}
	return (true);
}

int		find_min_or_max_index(t_list_stack *list, t_bool min)
{
	t_stack		*stack;
	int			perem;
	
	if (list->head)
	{
		stack = list->head->next;
		perem = list->head->index;
		while (stack != NULL)
		{
			if (min == true)
			{
				if (stack->index < perem)
					perem = stack->index;
			}
			else
			{
				if (stack->index > perem)
					perem = stack->index;
			}
			stack = stack->next;
		}
		return (perem);
	}
	else
		return (-1);
}

int		find_closest_index(t_list_stack *a, int index)
{
	t_stack		*stack;
	int			closest_index;
	int			temp;
	
	if (a->head)
	{
		stack = a->head;
		closest_index = stack->index;
		temp = ft_abs(stack->index - index);
		while (stack != NULL)
		{
			if (ft_abs(stack->index - index) == temp)
			{
				if (closest_index < stack->index)
					closest_index = stack->index;
			}
			else if (ft_abs(stack->index - index) < temp)
			{
				temp = ft_abs(stack->index - index);
				closest_index = stack->index;
			}
			stack = stack->next;
		}
		return(closest_index);
	}
	return (-1);
}

void	zero_to_head(t_list_stack *a, t_list_command *command)
{
	t_bool	flag;
	
	flag = rb_or_rrb(a, 0);
	while (a->head->index != 0)
	{
		if (flag == true)
			ra(a, command);
		else
			rra(a, command);
	}
}