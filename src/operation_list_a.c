/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/03/01 14:34:29 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list_stack *a, t_list_comand *list_command, t_bool markup)
{
	//swap a - swap the first 2 elements at the top of stack a. 
	//Do nothing if there is only one or no elements).
	t_stack		*stack;
	t_stack		*temp;
	
	if (a->head || a->head->next)
	{
		stack = a->head;
		temp = stack_copystack(stack->next, false);
		list_cut(a, stack->next, true);
		list_add2head(a, temp, true);
		free(temp);
		if (list_command != NULL)
			add_comand(list_command,"sa");
		if (markup == true)
			markup_index(a);
	}
}

void	pa(t_list_stack *a, t_list_stack *b, t_list_comand *list_command)
{
	//push a - take the first element at the top of b and put it at the top of a.
	//Do nothing if a is empty.
	t_stack	*temp;

	if (b->head)
	{
		temp = stack_copystack(b->head, false);
		list_cut(b, b->head, true);
		list_add2head(a, temp, true);
		free(temp);
		if (list_command != NULL)
			add_comand(list_command,"pa");
	}
}

void	ra(t_list_stack *a, t_list_comand *list_command)
{
	//rotate a - shift up all elements of stack a by 1.
	//The first element becomes the last one.
	t_stack			*old_stack;
	t_list_stack	*new_list;
	t_stack			*new_stack;

	old_stack = a->head;
	while (old_stack->next != NULL)
		old_stack = old_stack->next;
	new_list = (t_list_stack *)malloc(sizeof(t_list_stack));
	new_list->head = stack_copystack(old_stack, false);
	list_cut(a, old_stack, true);
	while (a->head != NULL)
	{
		old_stack = a->head;
		while (old_stack->next != NULL)
			old_stack = old_stack->next;
		new_stack = stack_copystack(old_stack, false);
		list_add2tail(new_list, new_stack, true);
		list_cut(a, old_stack, true);
		free(new_stack);
	}
	a->head = new_list->head;
	if (list_command != NULL)
			add_comand(list_command,"ra");
}

void	rra(t_list_stack *a, t_list_comand *list_command)
{
	//reverse rotate a - shift down all elements of stack a by 1. 
	//The last element becomes the first one.
	t_stack	*stack;
	t_stack	*temp;

	stack = a->head;
	temp = a->head;
	while (temp->next->next != NULL)
		temp = temp->next;
	list_add2head(a, temp->next, true);
	list_cut(a, temp->next, true);
	if (list_command != NULL)
			add_comand(list_command,"rra");
}