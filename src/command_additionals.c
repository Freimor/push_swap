/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_additionals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:53:31 by rick              #+#    #+#             */
/*   Updated: 2020/03/21 14:53:55 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_commands(t_list_stack *b)
{
	t_stack	*stack;

	if (b->head != NULL)
	{
		stack = b->head;
		while (stack != NULL)
		{
			free(stack->comand_list);
			stack->comand_list = NULL;
			stack = stack->next;
		}
	}
}