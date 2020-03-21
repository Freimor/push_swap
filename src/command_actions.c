/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:32:32 by freimor           #+#    #+#             */
/*   Updated: 2020/03/21 11:50:00 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	command_add(t_list_command *list_commands, char *command)
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

void	command_delete(t_list_command *list_commands, char *command)
{
	t_command	*commands;
	t_command	*temp;

	commands = list_commands->head;
	if (ft_strequ(list_commands->head->name, command) == 1)
	{
		if (list_commands->head->next == NULL)
			free(list_commands);
		else
		{
			temp = list_commands->head;
			list_commands->head = list_commands->head->next;
			free(temp);
		}
	}
	else
	{
		while (ft_strequ(commands->next->name, command) != 1)
			commands = commands->next;
		temp = commands->next;
		commands->next = commands->next->next;
		free(temp);
	}
}

void	command_replace(t_list_command *list_commands, char *remove, char *need)
{
	t_command	*commands;
	t_command	*temp;
	
	commands = list_commands->head;
	if (ft_strequ(list_commands->head->name, remove) == 1)
		list_commands->head->name = need;
	else
	{
		while (ft_strequ(commands->next->name, remove) != 1)
			commands = commands->next;
		temp = commands->next->next;
		commands->next->name = need;
		commands->next = temp;
	}
}

static void	double_command_replace(t_stack *stack, int array[])
{
	int	i;

	i = 0;
	while (array[0] > 0 && array[2] > 0)
	{
		command_replace(stack->comand_list, "rb", "rr");
		command_delete(stack->comand_list, "ra");
		array[0]--;
		array[2]--;
	}
	while (array[1] > 0 && array[3] > 0)
	{
		command_replace(stack->comand_list, "rrb", "rrr");
		command_delete(stack->comand_list, "rra");
		array[1]--;
		array[3]--;
	}
}

void	double_command_update(t_stack *stack, t_bool flag)
{
	t_command		*command;
	int				array[4];

	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
	
	command = stack->comand_list->head;
	if (flag == true)
	{
		array[0]--;
		array[1]--;
	}						// связь если ближайший индекс меньше того что пушим
	while (command != NULL)
	{
		if (ft_strequ(command->name, "ra") == 1)
			array[0]++;
		else if (ft_strequ(command->name, "rra") == 1)
			array[1]++;
		else if (ft_strequ(command->name, "rb") == 1)
			array[2]++;
		else if (ft_strequ(command->name, "rrb") == 1)
			array[3]++;
		command = command->next;
	}
	double_command_replace(stack, array);
}