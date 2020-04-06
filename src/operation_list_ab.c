/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:07:57 by freimor           #+#    #+#             */
/*   Updated: 2020/04/05 21:11:12 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list_stack *a, t_list_stack *b, t_list_command *list_command)
{
	//sa and sb at the same time.
	sa(a, NULL);
	sb(b, NULL);
	if (list_command != NULL)
			command_add(list_command,"ss");
}

void	rr(t_list_stack *a, t_list_stack *b, t_list_command *list_command)
{
	//ra and rb at the same time
	ra(a, NULL);
	rb(b, NULL);
	if (list_command != NULL)
			command_add(list_command,"rr");
}

void	rrr(t_list_stack *a, t_list_stack *b, t_list_command *list_command)
{
	//rra and rrb at the same time.
	rra(a, NULL);
	rrb(b, NULL);
	if (list_command != NULL)
			command_add(list_command,"rrr");
}