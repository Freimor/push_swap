/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_additionals_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 16:13:36 by rick              #+#    #+#             */
/*   Updated: 2020/03/27 16:14:29 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_command_list(int index, t_list_command *command, t_list_stack *a, t_list_stack *b)
{
	t_stack		*stack_b;
	t_command	*commands;

	stack_b = b->head;
	while (stack_b->index != index)
		stack_b = stack_b->next;
	commands = stack_b->comand_list->head;
    printf("выбранная голова %d : %s\n", stack_b->index, commands->name);
	while (commands != NULL)
	{
		if (ft_strequ("sa", commands->name) == 1)
			sa(a, command);
		else if (ft_strequ("pa", commands->name) == 1)
			pa(a, b, command);
		else if (ft_strequ("ra", commands->name) == 1)
			ra(a, command);
		else if (ft_strequ("rra", commands->name) == 1)
			rra(a, command);
		else if (ft_strequ("sb", commands->name) == 1)
			sb(b, command);
		else if (ft_strequ("pb", commands->name) == 1)
			pb(a, b, command);
		else if (ft_strequ("rb", commands->name) == 1)
			rb(b, command);
		else if (ft_strequ("rrb", commands->name) == 1)
			rrb(b, command);
		else if (ft_strequ("ss", commands->name) == 1)
			ss(a, b, command);
		else if (ft_strequ("rr", commands->name) == 1)
			rr(a, b, command);
		else if (ft_strequ("rrr", commands->name) == 1)
			rrr(a, b, command);
		commands = commands->next;
	}
}