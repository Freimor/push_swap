/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 12:45:53 by rick              #+#    #+#             */
/*   Updated: 2020/04/06 11:19:37 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		exec_command(char *command, t_list_stack *list, t_list_stack *b)
{
	if (ft_strequ(command, "sa") == 1)
		sa(list, NULL);
	else if (ft_strequ(command, "pa") == 1)
		pa(list, b, NULL);
	else if (ft_strequ(command, "ra") == 1)
		ra(list, NULL);
	else if (ft_strequ(command, "rra") == 1)
		rra(list, NULL);
	else if (ft_strequ(command, "sb") == 1)
		sb(b, NULL);
	else if (ft_strequ(command, "pb") == 1)
		pb(list, b, NULL);
	else if (ft_strequ(command, "rb") == 1)
		rb(b, NULL);
	else if (ft_strequ(command, "rrb") == 1)
		rrb(b, NULL);
	else if (ft_strequ(command, "ss") == 1)
		ss(list, b, NULL);
	else if (ft_strequ(command, "rr") == 1)
		rr(list, b, NULL);
	else if (ft_strequ(command, "rrr") == 1)
		rrr(list, b, NULL);
}

static t_bool	checker_validation(t_list_stack *list, t_list_command *command)
{
	t_command		*iter;
	t_list_stack	*b;
	
	b = (t_list_stack *)malloc(sizeof(t_list_stack));
	b->head = NULL;
	iter = command->head;
	while (iter != NULL)
	{
		exec_command(iter->name, list, b);
		iter = iter->next;
	}
	list_deleteall(b, false);
	return (check_align(list, true));
}

int	main(int ac, char **arg)
{
	t_list_stack	*numbers;
	t_list_stack	*copy;
	t_list_command	*commands;
	
	if ((numbers = input_fabrication(ac, arg)) == NULL)
		crash("Error\n");
	copy = list_copylist(numbers);
	list_indexing(copy);
	if ((commands = push_swap(numbers)) == NULL)
		crash("Error\n");
	print_commands(commands);
	if (checker_validation(copy, commands) == true)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	list_deleteall(copy, false);
	command_list_delete(commands);
	return (0);
}