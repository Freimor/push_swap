/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/04/05 21:11:18 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list_stack *b, t_list_command *list_command)
{
	//swap b - swap the first 2 elements at the top of stack b. 
	//Do nothing if there is only one or no elements).
	t_stack		*temp;
	t_stack	*temp_2;
	
	if (b->head && b->head->next)
	{
		temp = b->head;
		temp_2 = b->head->next->next;
		b->head = b->head->next;
		b->head->next = temp;
		b->head->next->next = temp_2;
		if (list_command != NULL)
			command_add(list_command,"sb");
	}
}

void	pb(t_list_stack *a, t_list_stack *b, t_list_command *list_command)
{
	//push a - take the first element at the top of a and put it at the top of b.
	//Do nothing if a is empty.
	t_stack	*temp;
	t_stack	*temp_2;

	if (a->head && b)
	{
		temp = a->head;
		a->head = a->head->next;
		temp_2 = b->head;
		b->head = temp;
		b->head->next = temp_2;
		a->size--;
		b->size++;
		if (list_command != NULL)
			command_add(list_command,"pb");
	}
}

void	rb(t_list_stack *b, t_list_command *list_command)
{
	//rotate a - shift up all elements of stack a by 1.
	//The first element becomes the last one.
	t_stack	*temp;
	t_stack	*temp_2;	//последний

	if (b->head && b->head->next != NULL)
	{
		temp = b->head;
		temp_2 = b->head;
		while (temp_2->next != NULL)
			temp_2 = temp_2->next;
		b->head = b->head->next;
		temp_2->next = temp;
		temp->next = NULL;
		if (list_command != NULL)
			command_add(list_command,"rb");
	}
}

void	rrb(t_list_stack *b, t_list_command *list_command)
{
	//reverse rotate b - shift down all elements of stack b by 1. 
	//The last element becomes the first one.
	t_stack	*temp;
	t_stack	*temp_2;
	t_stack *temp_3;

	if (b->head && b->head->next != NULL)
	{
		if (b->head->next->next == NULL)
			sb(b, NULL);
		else
		{
			temp = b->head;
			temp_2 = b->head;
			temp_3 = b->head;
			while (temp_2->next != NULL)
				temp_2 = temp_2->next;
			while (temp_3->next != temp_2)
				temp_3 = temp_3->next;
			b->head = temp_2;
			b->head->next = temp;
			temp_3->next = NULL;
		}
		if (list_command != NULL)
			command_add(list_command,"rrb");
	}
}