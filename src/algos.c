/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:06:20 by freimor           #+#    #+#             */
/*   Updated: 2020/03/03 15:07:51 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_a(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	t_stack	*stack_a;

	stack_a = a->head;
	while (check_keepin(a) == false)
	{
		if (sa_needed(a) == true)
			sa(a, command, true);
		if (a->head->keep_in == false)
			pb(a, b, command);
		else
			ra(a, command);
		ft_putchar('\n');
		print_list(a, true, true);
	}
}

void	solve_alogo(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	
}
