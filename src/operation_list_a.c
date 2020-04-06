/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/04/05 21:11:08 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list_stack *a, t_list_command *list_command)
{
	//swap a - swap the first 2 elements at the top of stack a. 
	//Do nothing if there is only one or no elements).
	t_stack	*temp;
	t_stack	*temp_2;

	if (a->head->next != NULL)
	{
		temp = a->head;
		temp_2 = a->head->next->next;
		a->head = a->head->next;
		a->head->next = temp;
		a->head->next->next = temp_2;
		if (list_command != NULL)
			command_add(list_command,"sa");
	}
}

void	pa(t_list_stack *a, t_list_stack *b, t_list_command *list_command)
{
	//push a - take the first element at the top of b and put it at the top of a.
	//Do nothing if a is empty.
	t_stack	*temp;
	t_stack	*temp_2;

	if (b->head)
	{
		temp = b->head;
		b->head = b->head->next;
		temp_2 = a->head;
		command_list_delete(temp->comand_list);
		temp->comand_list = NULL;
		a->head = temp;
		a->head->next = temp_2;
		b->size--;
		a->size++;
		if (list_command != NULL)
			command_add(list_command,"pa");
	}
}

void	ra(t_list_stack *a, t_list_command *list_command)
{
	//rotate a - shift up all elements of stack a by 1.
	//The first element becomes the last one.
	t_stack	*temp;		//первый
	t_stack	*temp_2;	//последний

	if (a->head->next != NULL)
	{
		temp = a->head;
		temp_2 = a->head;
		while (temp_2->next != NULL)
			temp_2 = temp_2->next;
		a->head = a->head->next;
		temp_2->next = temp;
		temp->next = NULL;
		if (list_command != NULL)
			command_add(list_command,"ra");
	}
}

void	rra(t_list_stack *a, t_list_command *list_command)
{
	//reverse rotate a - shift down all elements of stack a by 1. 
	//The last element becomes the first one.
	t_stack	*temp;
	t_stack	*temp_2;
	t_stack *temp_3;

	if (a->head->next != NULL)
	{
		if (a->head->next->next == NULL)
			sa(a, NULL);
		else
		{
			temp = a->head;
			temp_2 = a->head;
			temp_3 = a->head;
			while (temp_2->next != NULL)
				temp_2 = temp_2->next;
			while (temp_3->next != temp_2)
				temp_3 = temp_3->next;
			a->head = temp_2;
			a->head->next = temp;
			temp_3->next = NULL;
		}
		if (list_command != NULL)
			command_add(list_command,"rra");
	}
}