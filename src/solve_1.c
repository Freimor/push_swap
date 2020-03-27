/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:55:53 by freimor           #+#    #+#             */
/*   Updated: 2020/03/27 16:24:04 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		mantiss(t_list_stack *list)
{
	int		summ;
	int		i;
	t_stack	*stack;

	summ = 0;
	i = 0;
	stack = list->head;
	while (stack != NULL)
	{
		i++;
		summ += stack->index;
		stack = stack->next;
	}
	return (summ / i);
}

t_bool		check_listmantiss(t_list_stack *list, int mantiss)
{
	t_stack *stack;

	stack = list->head;
	while (stack != NULL)
	{
		if (stack->index < mantiss)
			return(false);
		stack = stack->next;
	}
	return (true);
}

void	targetstack2head_b(t_list_stack *b, t_list_command *command,  int index)
{
	t_stack	*stack;
	int		a;
	int		c;
	
	a = 0;
	stack = b->head;
	while (stack != NULL)
	{
		a++;
		if (stack->index == index)
			c = a;											////// a->5  b->3  
		stack = stack->next;
	}
	while (b->head->index != index)
	{
		if (b->head->next->index == index)
			sb(b, command);
		else if (a - c < c)
			rrb(b, command);
		else
			rb(b, command);
	}
}

/*void	solve_try_2(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int	save_index;
	
	save_index = -1;
	ra(a, command);
	while (check_align(a) == false || b->head != NULL)						///add rule swap maybe??
	{
		if (a->head->next->index == save_index + 1)
		{
			sa(a, command, false);
			save_index = a->head->index;
			ra(a, command);
		}
		else if (a->head->index == (save_index + 1))
		{
			save_index = a->head->index;
			ra(a, command);
		}
		else if ((b->head != NULL) && (find_stack(b, save_index + 1) != NULL))
		{
			targetstack2head_b(b, command, save_index + 1);
			pa(a, b, command);
			save_index = a->head->index;
			ra(a, command);
		}
		else
		{
			if (a->head->index > save_index + 1)
				pb(a, b, command);
			else
				rra(a, command);
		}
	}
}*/

/*int		find_closest_index(t_list_stack *a, int index)
{
	t_stack		*stack;
	int			min;
	int			max;
	int			temp_min;
	int			temp_max;
	
	if (a->head)
	{
		stack = a->head;
		min = find_min_or_max(a, true);
		//max = find_min_or_max(a, false);

		temp_min = find_min_or_max(a, false);
		temp_max = find_min_or_max(a, false);
		while (stack != NULL)
		{
			if (stack->index < index && ft_abs(index - stack->index) < temp_min)
			{
				min = stack->index;
				temp_min = ft_abs(index - stack->index);
			}
			else if (stack->index > index && ft_abs(index - stack->index) < temp_max)
			{
				max = stack->index;
				temp_max = ft_abs(index - stack->index);
			}
			stack = stack->next;
		}
		if (temp_min < temp_max)
			return (min);
		else
			return (max);
	}
	return (-1);
}*/

void		solve_after_presort(t_list_stack *a, t_list_command *command)			//rabotaet ispravno
{
	if (list_len(a) == 2)
	{
		if (a->head == a->head->next + 1)
			sa(a, command);
	}
	else if (list_len(a) == 3)
	{
		while (check_align(a, false) == false)
		{
			if ((a->head->index == a->head->next->index + 2
			&& a->head->index == a->head->next->next->index + 1) ||
			(a->head->index + 2 == a->head->next->index
			&& a->head->index + 1 == a->head->next->next->index))
				ra(a, command);
			else if (a->head->index + 1 == a->head->next->index
			&& a->head->index == a->head->next->next->index + 1)
				rra(a, command);
			else if ((a->head->index == a->head->next->index + 1
			&& a->head->index == a->head->next->next->index + 2) ||
			(a->head->index == a->head->next->index + 1
			&& a->head->index + 1 == a->head->next->next->index))
				sa(a, command);
		}
	}
}

void		drops(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int		mantissa;
	t_bool	flag;
	t_stack	*stack_bottom;

	stack_bottom = a->head;
	while (stack_bottom->next != NULL)
			stack_bottom = stack_bottom->next;
	mantissa = mantiss(a);
	flag = false;
	while (flag == false)
	{
		if (a->head == stack_bottom)
			flag = true;
		if (a->head->index < mantissa)
			pb(a, b, command);
		else
			ra(a, command);
	}
}

void		presort_a(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	while (list_len(a) > 3)
	{
		drops(a, b, command);
	}
	solve_after_presort(a, command);
}

/*void	add_command_to_main_list(t_list_command *add, t_list_command *main)
{
	t_command	*src;
	t_command	*dst;
	
	dst = main->head;
	src = add->head;
	while (dst->next != NULL)
		dst = dst->next;
	while (src != NULL)
	{
		dst->next = (t_command *)malloc(sizeof(t_command));
		dst->name = ft_strcpy(dst->name, src->name);
		dst->next = NULL;
		src = src->next;
	}
}*/

/*void	exec_command(char	*str, t_list_command *command, t_list_stack *a, t_list_stack *b)
{
	if (ft_strequ("sa", str) == 1)
		sa(a, command);
	else if (ft_strequ("pa", str) == 1)
		pa(a, b, command);
	else if (ft_strequ("ra", str) == 1)
		ra(a, command);
	else if (ft_strequ("rra", str) == 1)
		rra(a, command);
	else if (ft_strequ("sb", str) == 1)
		sb(a, command);
	else if (ft_strequ("pb", str) == 1)
		pb(a, b, command);
	else if (ft_strequ("rb", str) == 1)
		rb(a, command);
	else if (ft_strequ("rrb", str) == 1)
		rrb(a, command);
	else if (ft_strequ("ss", str) == 1)
		ss(a, b, command);
	else if (ft_strequ("rr", str) == 1)
		rr(a, b, command);
	else if (ft_strequ("rrr", str) == 1)
		rrr(a, b, command);
}*/
