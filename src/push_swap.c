/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/02 15:45:44 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **arg)
{
	t_list_stack	*list;
	t_list_command	*command;
	int				i;

	i = 1;
	list = (t_list_stack *)malloc(sizeof(t_list_stack));
	command = (t_list_command *)malloc(sizeof(t_list_command));
	list->head = NULL;
	command->head = NULL;
	command->size = 0;
	if (input_checker(ac, arg) == false)
		return (-1);
	if (check_listfordup(list, ac, arg) == false)
	{
		list_deleteall(list);
		return (-1);
	}
	list->size = list_len(list);
	list_indexing(list);
	solve(list, command);
	list_deleteall(list);
	command_list_delete(command);
	return (0);
}