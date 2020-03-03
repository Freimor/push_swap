/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:50:38 by freimor           #+#    #+#             */
/*   Updated: 2020/03/03 14:47:55 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			set_index(t_list_stack *sortlist)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = sortlist->head;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

t_list_stack	*list_sort_ascending(t_list_stack *list)
{
	t_list_stack	*new_list;
	t_stack			*new_stack;
	t_stack			*temp;
	t_bool			flag_sort;

	flag_sort = false;
	new_list = list_copylist(list);
	new_stack = new_list->head;
	while (flag_sort == false)
	{
		flag_sort = true;
		while (new_stack->next != NULL)
		{
			if (new_stack->num > new_stack->next->num)
			{
				temp = stack_copystack(new_stack->next, false);
				list_cut(new_list, new_stack->next, true);
				list_add2head(new_list, temp, true);
				free(temp);
				flag_sort = false;
				new_stack = new_list->head;
				break ;
			}
			new_stack = new_stack->next;
		}
	}
	return(new_list);
}

t_stack	*list_apply_index(t_list_stack *dst, t_list_stack *src)
{
	t_stack	*src_stack;
	t_stack	*dst_stack;
	t_stack	*first;

	dst_stack = dst->head;
	src_stack = src->head;
	while (dst_stack != NULL)
	{
		while (dst_stack->num != src_stack->num)
			src_stack = src_stack->next;
		dst_stack->index = src_stack->index;
		dst_stack = dst_stack->next;
		src_stack = src->head;
	}
	dst_stack = dst->head;
	while (dst_stack->index != 0)
		dst_stack = dst_stack->next;
	return(dst_stack);
}

void	markup_big(t_list_stack *list)
{
	t_list_stack	*index_list;
	t_stack			*old_stack;
	t_stack			*index_stack;
	t_stack			*first;
	int				index;

	index_list = list_sort_ascending(list);
	set_index(index_list);
	first = list_apply_index(list, index_list);
	index_stack = index_list->head;
	old_stack = list->head;
	first->keep_in = true;
	index = first->index;
	while (old_stack != NULL)
	{
		if (old_stack->index == (index + 1))
		{
			old_stack->keep_in = true;
			index = old_stack->index;
		}
		else if (old_stack != first)
			old_stack->keep_in = false;
		old_stack = old_stack->next;
	}
	list_deleteall(index_list);
}

void	markup_small(t_list_stack *list)
{
	t_stack	*stack;
	int		index;
	int		i;
	int		min;

	i = 1;
	stack = list->head;
	min = list->head->index;
	while (stack != NULL)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	stack = list->head;
	while (stack->index != min)
		stack = stack->next;
	index = stack->index;
	stack = list->head;
	while (stack != NULL)
	{
		if (stack->index == (index + i))
		{
			stack->keep_in = true;
			i++;
		}
		else if (stack->index != index)
			stack->keep_in = false;
		stack = stack->next;
	}
}