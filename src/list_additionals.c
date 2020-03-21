/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_additionals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:50:07 by rick              #+#    #+#             */
/*   Updated: 2020/03/21 14:52:09 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack			*stack_copystack(t_stack *stack, t_bool save_next)
{
	t_stack	*new_stack;
	
	new_stack = (t_stack *)malloc(sizeof(t_stack));
	new_stack->num = stack->num;
	new_stack->index = stack->index;
	new_stack->comand_list = NULL;
	if (save_next == true)
		new_stack->next = stack->next;
	else
		new_stack->next = NULL;
	return(new_stack);
}

int		list_len(t_list_stack *list)
{
	int		len;
	t_stack *stack;

	len = 0;
	stack = list->head;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack		*find_stack(t_list_stack *list, int index)
{
	t_stack *stack;

	if (list != NULL && list->head != NULL)
	{
		stack = list->head;
		while (stack != NULL)
		{
			if (stack->index == index)
				return (stack);
			stack = stack->next;
		}
	}
	return (NULL);
}