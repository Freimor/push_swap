/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_additionals.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 20:32:32 by rick              #+#    #+#             */
/*   Updated: 2020/04/06 11:13:16 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			crash(char *str)
{
	ft_putstr(str);
	exit(1);
}

t_list_stack	*input_fabrication(int ac, char **arg)
{
	t_list_stack	*list;

	if (input_checker(ac, arg) == false)
		return (NULL);
	list = (t_list_stack *)malloc(sizeof(t_list_stack));
	list->head = NULL;
	list->size = 0;
	if (check_listfordup(list, ac, arg) == false)
	{
		list_deleteall(list, true);
		return (NULL);
	}
	return (list);
}

t_list_command	*push_swap(t_list_stack *list)
{
	t_list_command	*command;

	command = (t_list_command *)malloc(sizeof(t_list_command));
	command->head = NULL;
	command->size = 0;
	list->size = list_len(list);
	list_indexing(list);
	solve(list, command);
	list_deleteall(list, false);
	return (command);
}
