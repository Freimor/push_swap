/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_algoritm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:02:53 by rick              #+#    #+#             */
/*   Updated: 2020/04/02 15:18:56 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		attribute_apply(t_list_stack *list, t_list_stack *temp)
{
	t_stack *stack;
	t_stack *temp_stack;

	stack = list->head;
	while (stack != NULL)
	{
		temp_stack = temp->head;
		while (temp_stack != NULL)
		{
			if (temp_stack->index == stack->index)
				stack->flag = temp_stack->flag;
			temp_stack = temp_stack->next;
		}
		stack = stack->next;
	}
}

static int		sort_combo(t_list_stack *list, int index, t_bool mark)
{
	t_list_stack *temp_list;
	int		count;
	int		temp;

	temp_list = list_copylist(list);
	count = 1;
	while (temp_list->head->index != index)
		ra(temp_list, NULL);
	temp = temp_list->head->index;
	temp_list->head->flag = true;
	ra(temp_list, NULL);
	while (temp_list->head->index != index)
	{
		if (temp_list->head->next->index == temp + 1)
		{
			sa(temp_list, NULL);
			temp_list->head->flag = true;
			ra(temp_list, NULL);
			count++;
			temp++;
		}
		else if (temp_list->head->index == temp + 1)
		{
			temp_list->head->flag = true;
			ra(temp_list, NULL);
			count++;
			temp++;
		}
		else
			ra(temp_list, NULL);
	}
	if (mark == true)
		attribute_apply(list, temp_list);
	list_deleteall(temp_list);
	return (count);
}

static int		check_where_start(t_list_stack *list)
{
	t_stack	*stack;
	int		index;
	int		max_sort_elem;

	stack = list->head;
	max_sort_elem = 0;
	while (stack != NULL)
	{
		if (sort_combo(list, stack->index, false) > max_sort_elem)
		{
			max_sort_elem = sort_combo(list, stack->index, false);
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

void			solve_first(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int		start_index;
	t_bool	flag;
	
	start_index = check_where_start(a);
	sort_combo(a, start_index, true);
	flag = rb_or_rrb(a, start_index);
	while (a->head->index != start_index)
	{
		if (flag == true)
			ra(a, command);
		else
			rra(a, command);
	}
	while (check_align(a, true) == false)
	{
		if (a->head->next->index + 1 == a->head->index && a->head->next->flag == true)
			sa(a, command);
		else if (a->head->flag == true)
			ra(a, command);
		else
			pb(a, b, command);
	}
}