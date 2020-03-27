/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:17:34 by freimor           #+#    #+#             */
/*   Updated: 2020/03/27 22:38:06 by rick             ###   ########.fr       */
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
		temp = stack_copystack(node, false);
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
		temp = stack_copystack(node, false);
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
	if (list->head == cut_node)
	{
		if (list->head->next == NULL)
			list->head = NULL;
			//free(list->head);
		else
			list->head = stack->next;
	}
	else
	{
		while (stack->next != cut_node)
			stack = stack->next;
		temp = stack->next->next;
		stack->next = temp;
	}
	if (delete == true)
		free(cut_node);
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
		new_stack = (t_stack *)malloc(sizeof(t_stack));
		new_list->head = new_stack;
		new_list->size = old->size;
		new_stack->num = stack->num;
		new_stack->index = stack->index;
		new_stack->flag = stack->flag;
		new_stack->comand_list = NULL;
		while (stack->next != NULL)
		{
			new_stack->next = (t_stack *)malloc(sizeof(t_stack));
			new_stack = new_stack->next;
			stack = stack->next;
			new_stack->num = stack->num;
			new_stack->index = stack->index;
			new_stack->flag = stack->flag;
			new_stack->comand_list = NULL;
		}
		new_stack->next = NULL;
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
	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			temp = stack->next;
			if (stack->comand_list != NULL)
				free(stack->comand_list);
			free(stack);
			stack = temp;
		}
		if (stack->comand_list != NULL)
				free(stack->comand_list);
			free(stack);
	}
	free(list);
}
