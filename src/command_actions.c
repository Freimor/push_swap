/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:32:32 by freimor           #+#    #+#             */
/*   Updated: 2020/02/28 19:56:07 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_comand(t_list_comand *list_comands, char *comand)
{
	t_comand	*comands;

	comands = list_comands->head;
	if (comands == NULL)
	{
		comands = (t_comand *)malloc(sizeof(t_comand));
		comands->name = comand;
		comands->next = NULL;
	}
	else
	{
		while (comands->next != NULL)
			comands = comands->next;
		comands->next = (t_comand *)malloc(sizeof(t_comand));
		comands->next->name = comand;
		comands->next->next = NULL;
	}
}

t_bool	sa_needed(t_list_stack *list)
{
	t_stack	*stack;
	int		a;
	int		b;

	a = 0;
	b = 0;
	stack = list->head;
	while (stack != NULL)
	{
		if (stack->keep_in == true)
			a++;
		stack = stack->next;
	}
	sa(list, NULL, true);
	stack = list->head;
	while (stack != NULL)
	{
		if (stack->keep_in == true)
			b++;
		stack = stack->next;
	}
	sa(list, NULL, true);
	if (b > a)
		return (true);
	return (false);
}