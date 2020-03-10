/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:32:32 by freimor           #+#    #+#             */
/*   Updated: 2020/03/10 14:17:19 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_command(t_list_command *list_commands, char *command)
{
	t_command	*commands;

	if (list_commands->head == NULL)
	{
		list_commands->head = (t_command *)malloc(sizeof(t_command));
		list_commands->head->name = command;
		list_commands->head->next = NULL;
		list_commands->size++;
	}
	else
	{
		commands = list_commands->head;
		while (commands->next != NULL)
			commands = commands->next;
		commands->next = (t_command *)malloc(sizeof(t_command));
		commands->next->name = command;
		commands->next->next = NULL;
		list_commands->size++;
	}
}

t_bool	sa_needed(t_list_stack *list)
{
	t_stack			*stack;
	t_stack			*teststack;;
	t_list_stack	*testlist;
	int				a;
	int				b;

	a = 0;
	b = 0;
	stack = list->head;
	if (list->head->next == NULL)
		return (false);
	testlist = list_copylist(list);
	teststack = testlist->head;
	while (stack != NULL)
	{
		if (stack->keep_in == true)
			a++;
		stack = stack->next;
	}
	sa(testlist, NULL, true);
	while (teststack != NULL)
	{
		if (teststack->keep_in == true)
			b++;
		teststack = teststack->next;
	}
	free(testlist);
	if (b > a)
		return (true);
	return (false);
}