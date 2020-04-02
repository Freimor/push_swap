/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_additionals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:53:31 by rick              #+#    #+#             */
/*   Updated: 2020/04/02 17:39:52 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_commands(t_list_stack *b)
{
	t_stack		*stack;
	t_command	*iter;
	t_command	*temp;

	if (b->head != NULL)
	{
		stack = b->head;
		while (stack != NULL)
		{
			if (stack->comand_list->head)
			{
				iter = stack->comand_list->head;
				while (iter)
				{
					temp = iter;
					iter = iter->next;
					free(temp->name);
					free(temp);
				}
				stack->comand_list->head = NULL;
				stack->comand_list->size = 0;
			}
			stack = stack->next;
		}
	}
}

void	command_list_delete(t_list_command *command)
{
	t_command	*iter;
	t_command	*temp;
	
	if (command)
	{
		iter = command->head;
		while (iter != NULL)
		{
			temp = iter;
			iter = iter->next;
			free(temp->name);
			free(temp);
		}
		free(command);
	}
}

void	command_locallist(t_stack *stack, t_list_command *command)
{
	t_command	*iter_command;

	if (command && command->head)
	{
		iter_command = command->head;
		stack->comand_list = (t_list_command *)malloc(sizeof(t_list_command));
		stack->comand_list->head = NULL;
		stack->comand_list->size = command->size;
		while (iter_command != NULL)
		{
			command_add(stack->comand_list, iter_command->name);
			iter_command = iter_command->next;
		}
	}
}

/*void	command_set_sizes(t_list_stack *b)
{
	t_stack		*stack;
	t_command	*command;

	stack = b->head;
	while (stack != NULL)
	{
		stack->comand_list->size = 0;
		if (stack->comand_list)
		{
			command = stack->comand_list->head;
			while (command != NULL)
			{
				stack->comand_list->size++;
				command = command->next;
			}
		}
		stack = stack->next;
	}
}*/

t_list_command	*command_list_copy(t_list_command *list)
{
	t_list_command	*new;
	t_command		*temp;

	if (list)
	{
		new = (t_list_command *)malloc(sizeof(t_list_command));
		new->head = NULL;
		if (list->head)
		{
			temp = list->head;
			while (temp)
			{
				command_add(new, temp->name);
				temp = temp->next;
			}
		}
	}
	return (new);
}

t_bool			find_command(t_list_command *list, char *command)
{
	t_command *iter;

	iter = list->head;
	while (iter)
	{
		if (ft_strequ(iter->name, command) == true)
			return (true);
		iter = iter->next;
	}
	return (false);
}