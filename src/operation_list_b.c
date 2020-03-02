/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/03/01 14:34:07 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_list_stack *b, t_list_comand *list_command, t_bool markup)
{
	//swap b - swap the first 2 elements at the top of stack b. 
	//Do nothing if there is only one or no elements).
	t_stack		*stack;
	t_stack		*temp;
	
	if (b->head || b->head->next)
	{
		stack = b->head;
		temp = stack_copystack(stack->next, false);
		list_cut(b, stack->next, true);
		list_add2head(b, temp, true);
		free(temp);
		if (list_command != NULL)
			add_comand(list_command,"sb");
		if (markup == true)
			markup_index(b);
	}
}

void	pb(t_list_stack *a, t_list_stack *b, t_list_comand *list_command)
{
	//push b - take the first element at the top of a and put it at the top of b.
	//Do nothing if a is empty.
	t_stack	*temp;

	if (b->head)
	{
		temp = stack_copystack(b->head, false);
		list_cut(b, b->head, true);
		list_add2head(a, temp, true);
		free(temp);
		if (list_command != NULL)
			add_comand(list_command,"pb");
	}
}

void	rb(t_list_stack *b, t_list_comand *list_command)
{
	//rotate b - shift up all elements of stack b by 1.
	//The first element becomes the last one.
	t_stack			*old_stack;
	t_list_stack	*new_list;
	t_stack			*new_stack;

	old_stack = b->head;
	while (old_stack->next != NULL)
		old_stack = old_stack->next;
	new_list = (t_list_stack *)malloc(sizeof(t_list_stack));
	new_list->head = stack_copystack(old_stack, false);
	list_cut(b, old_stack, true);
	while (b->head != NULL)
	{
		old_stack = b->head;
		while (old_stack->next != NULL)
			old_stack = old_stack->next;
		new_stack = stack_copystack(old_stack, false);
		list_add2tail(new_list, new_stack, true);
		list_cut(b, old_stack, true);
		free(new_stack);
	}
	b->head = new_list->head;
	if (list_command != NULL)
			add_comand(list_command,"rb");
}

void	rrb(t_list_stack *b, t_list_comand *list_command)
{
	//reverse rotate b - shift down all elements of stack b by 1. 
	//The last element becomes the first one.
	t_stack	*stack;
	t_stack	*temp;

	stack = b->head;
	temp = b->head;
	while (temp->next->next != NULL)
		temp = temp->next;
	list_add2head(b, temp->next, true);
	list_cut(b, temp->next, true);
	if (list_command != NULL)
			add_comand(list_command,"rrb");
}