/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/02/28 20:56:52 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list_stack *list_stack, t_list_comand *list_command, t_bool markup)
{
	//swap a - swap the first 2 elements at the top of stack a. 
	//Do nothing if there is only one or no elements).
	t_stack		*stack;
	t_stack		*temp;
	
	if (list_stack->head || list_stack->head->next)
	{
		stack = list_stack->head;
		temp = stack_copystack(stack->next, false);
		list_cut(list_stack, stack->next, true);
		list_add2head(list_stack, temp, true, false);
		free(temp);
		if (list_command != NULL)
			add_comand(list_command,"sa");
		if (markup == true)
			markup_index(list_stack);
	}
}

void	pb(t_list_stack *a, t_list_stack *b, t_list_comand *list_command)
{
	//push b - take the first element at the top of a and put it at the top of b.
	//Do nothing if a is empty.
	t_stack	*temp;

	if (a->head)
	{
		temp = stack_copystack(a->head, false);
		list_cut(a, a->head, true);
		list_add2head(b, temp, true, false);
		free(temp);
		if (list_command != NULL)
			add_comand(list_command,"pb");
	}
}

void	ra(t_list_stack *a, t_list_comand *list_command)
{
	//rotate a - shift up all elements of stack a by 1.
	//The first element becomes the last one.
	t_list_stack *list_new;
	t_stack	*stack;
	t_stack	*temp;
	t_bool	f;

	f = true;
	stack = a->head;
	while (stack != NULL)
	{
		temp = stack_copystack(stack, false);
		if (f == true)
		{
			list_add2head(list_new, temp, true, true);
			f = false;
		}
		else
			list_add2head(list_new, temp, true, false);
		free(temp);
		temp = stack->next;
		list_cut(list_new, stack, true);
		stack = temp;
	}
	a->head = list_new->head;
	free(list_new);			//DEBUG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
}