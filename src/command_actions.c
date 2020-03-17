/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:32:32 by freimor           #+#    #+#             */
/*   Updated: 2020/03/16 15:28:14 by sskinner         ###   ########.fr       */
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

/*void	remove_command(t_list_command *list_command, char *s_command)
{
	t_command	*
}*/