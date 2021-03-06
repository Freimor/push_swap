/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_actions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 15:52:04 by rick              #+#    #+#             */
/*   Updated: 2020/04/07 14:10:49 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	form_first_list(t_list_stack *list, int num)	/* CHECKED */
{
	t_stack *stack;

	if (list->head == NULL)
	{
		list->head = (t_stack *)malloc(sizeof(t_stack));
		ft_bzero(list->head, sizeof(t_stack));		//pomoglo
		list->head->num = num;
		list->head->next = NULL;
		list->head->index = -1;
		list->head->comand_list = NULL;
	}
	else
	{
		stack = list->head;
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		ft_bzero(stack->next, sizeof(t_stack));		//pomoglo
		stack->next->num = num;
		stack->next->next = NULL;
		stack->next->index = -1;
		stack->next->comand_list = NULL;
	}
	list->size++;
}

t_bool	list_checkduplicate(t_list_stack *list)	/* CHECKED */
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
