/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/03/05 14:06:20 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_list_stack *b, t_list_command *list_command, t_bool mark)
{
	//swap b - swap the first 2 elements at the top of stack b. 
	//Do nothing if there is only one or no elements).
	t_stack		*stack;
	t_stack		*temp;
	
	if (b->head && b->head->next)
	{
		stack = b->head;
		temp = stack_copystack(stack->next, false);
		list_cut(b, stack->next, true);
		list_add2head(b, temp, true);
		free(temp);
		if (list_command != NULL)
			add_command(list_command,"sb");
		if (mark == true)
			markup(b, false);
	}
}

void	pb(t_list_stack *a, t_list_stack *b, t_list_command *list_command)
{
	//push b - take the first element at the top of a and put it at the top of b.
	//Do nothing if a is empty.
	t_stack	*temp;

	if (b->head == NULL)
	{
		b->head = (t_stack *)malloc(sizeof(t_stack));
		b->head->index = -1;
	}
	if (b->head)
	{
		temp = stack_copystack(a->head, false);
		list_cut(a, a->head, true);
		if (b->head->index == -1)
		{
			b->head->num = temp->num;
			b->head->index = temp->index;
			b->head->keep_in = temp->keep_in;
			b->head->next = NULL;
		}
		else
			list_add2head(b, temp, true);
		free(temp);
		if (list_command != NULL)
			add_command(list_command,"pb");
	}
}

void	rb(t_list_stack *b, t_list_command *list_command)
{
	//rotate a - shift up all elements of stack a by 1.
	//The first element becomes the last one.
	t_stack	*stack;

	stack = b->head;
	list_add2tail(b, stack, true);
	list_cut(b, b->head, true);
	if (list_command != NULL)
			add_command(list_command,"rb");
}

void	rrb(t_list_stack *b, t_list_command *list_command)
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
			add_command(list_command,"rrb");
}