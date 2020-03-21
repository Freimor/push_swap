/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:43:27 by rick              #+#    #+#             */
/*   Updated: 2020/03/21 15:50:49 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			set_index(t_list_stack *sortlist)
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

static t_list_stack	*list_sort_ascending(t_list_stack *list)
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

static t_stack		*list_apply_index(t_list_stack *dst, t_list_stack *src)
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

void				list_indexing(t_list_stack *list)
{
	t_list_stack	*index_list;

	index_list = list_sort_ascending(list);
	set_index(index_list);
	list_apply_index(list, index_list);
	list_deleteall(index_list);
}