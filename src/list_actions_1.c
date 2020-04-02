/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_actions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:17:34 by freimor           #+#    #+#             */
/*   Updated: 2020/04/01 21:19:28 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_add2head(t_list_stack *list, t_stack *node, t_bool copy)
{
	t_stack	*stack;
	t_stack *temp;

	if (copy == false)
	{
		stack = list->head;
		list->head = node;
		node->next = stack;
	}
	else
	{
		temp = stack_copystack(node);
		stack = list->head;
		list->head = temp;
		temp->next = stack;
	}
}

void	list_add2tail(t_list_stack *list, t_stack *node, t_bool copy)
{
	t_stack	*stack;
	t_stack *temp;

	if (copy == false)
	{
		stack = list->head;
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = node;
	}
	else
	{
		temp = stack_copystack(node);
		stack = list->head;
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = temp;
	}
}

void	list_cut(t_list_stack *list, t_stack *cut_node, t_bool delete)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = list->head;
	if (stack == cut_node)
	{
		temp = stack;
		list->head = stack->next;
	}
	else
	{
		while (stack->next != cut_node)
			stack = stack->next;
		temp = stack->next;
		stack->next = stack->next->next;
	}
	if (delete == true)
	{
		if (temp->comand_list != NULL)
			command_list_delete(temp->comand_list);
		free(temp);
	}
}

t_list_stack	*list_copylist(t_list_stack *old)
{
	t_stack			*stack;
	t_stack			*new_stack;
	t_list_stack	*new_list;

	stack = old->head;
	new_list = (t_list_stack *)malloc(sizeof(t_list_stack));
	if (old->head != NULL)
	{
		new_list->head = stack_copystack(stack);
		new_list->size = old->size;
		new_stack = new_list->head;
		while (stack->next != NULL)
		{
			new_stack->next = stack_copystack(stack->next);
			new_stack = new_stack->next;
			stack = stack->next;
		}
	}
	else
		new_list->head = NULL;
	return (new_list);
}

void			list_deleteall(t_list_stack *list)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = list->head;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		if (temp->comand_list != NULL)
			command_list_delete(temp->comand_list);
		free(temp);
	}
	free(list);
}