/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:50:38 by freimor           #+#    #+#             */
/*   Updated: 2020/02/28 20:51:12 by freimor          ###   ########.fr       */
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
				list_add2head(new_list, temp, true, false);
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

void	list_apply_index(t_list_stack *dst, t_list_stack *src)
{
	t_stack	*src_stack;
	t_stack	*dst_stack;

	dst_stack = dst->head;
	src_stack = src->head;
	while (dst_stack!= NULL)
	{
		while (dst_stack->num != src_stack->num)
			src_stack = src_stack->next;
		dst_stack->index = src_stack->index;
		dst_stack = dst_stack->next;
		src_stack = src->head;
	}
}

void	markup_index(t_list_stack *list)
{
	t_list_stack	*index_list;
	t_stack			*old_stack;
	t_stack			*index_stack;
	int				index;

	index_list = list_sort_ascending(list);
	set_index(index_list);
	list_apply_index(list, index_list);
	index_stack = index_list->head;
	old_stack = list->head;
	old_stack->keep_in = true;
	index = old_stack->index;
	while (old_stack->next != NULL)
	{
		if (old_stack->next->index == (index + 1))
		{
			old_stack->next->keep_in = true;
			index = old_stack->next->index;
		}
		else
			old_stack->next->keep_in = false;
		old_stack = old_stack->next;
	}
	list_deleteall(index_list);
}