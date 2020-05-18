/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:43:27 by rick              #+#    #+#             */
/*   Updated: 2020/05/18 11:39:18 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			list_all_elem_count(t_list_stack *list)
{
	t_stack *stack;
	int		count;

	count = 0;
	stack = list->head;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void				list_indexing(t_list_stack *list)
{
	t_stack	*stack;
	t_stack	*iter;
	int		i;

	stack = list->head;
	while (stack != NULL)
	{
		i = 0;
		if (stack->next == NULL)
			iter = list->head;
		else
			iter = stack->next;
		while (iter != stack)
		{
			if (iter->num > stack->num)
				i++;
			if (iter->next == NULL)
				iter = list->head;
			else
				iter = iter->next;
		}
		stack->index = list_all_elem_count(list) - i - 1;
		stack = stack->next;
	}
}