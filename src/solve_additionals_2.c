/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_additionals_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 16:13:36 by rick              #+#    #+#             */
/*   Updated: 2020/04/02 10:37:46 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_command_list(t_list_command *local, t_list_command *command, t_list_stack *a, t_list_stack *b)
{
	t_list_command	*temp;
	t_command		*iter;

	temp = command_list_copy(local);
	iter = temp->head;
	while (iter != NULL)
	{
		if (ft_strequ("sa", iter->name) == 1)
			sa(a, command);
		else if (ft_strequ("pa", iter->name) == 1)
			pa(a, b, command);							/// после pa лист команд рвется (элемент удаляется из b)
		else if (ft_strequ("ra", iter->name) == 1)
			ra(a, command);
		else if (ft_strequ("rra", iter->name) == 1)
			rra(a, command);
		else if (ft_strequ("sb", iter->name) == 1)
			sb(b, command);
		else if (ft_strequ("pb", iter->name) == 1)
			pb(a, b, command);
		else if (ft_strequ("rb", iter->name) == 1)
			rb(b, command);
		else if (ft_strequ("rrb", iter->name) == 1)
			rrb(b, command);
		else if (ft_strequ("ss", iter->name) == 1)
			ss(a, b, command);
		else if (ft_strequ("rr", iter->name) == 1)
			rr(a, b, command);
		else if (ft_strequ("rrr", iter->name) == 1)
			rrr(a, b, command);
		iter = iter->next;
	}
	command_list_delete(temp);
}