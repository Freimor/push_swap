/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_algoritm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 15:02:53 by rick              #+#    #+#             */
/*   Updated: 2020/03/21 17:13:07 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	sa_needed(t_list_stack *list)
{
	t_stack	*stack;
	int		temp;
	int		a;
	int		b;

	a = 1;
	b = 1;
	stack = list->head;
	temp = stack->index;
	while (stack->next != NULL)
	{
		if (stack->next->index == temp + 1)
		{
			temp++;
			a++;
		}
		stack = stack->next;
	}
	sa(list, NULL);
	stack = list->head;
	temp = stack->index;
	while (stack != NULL)
	{
		if (stack->next->index == temp + 1)
		{
			temp++;
			b++;
		}
		stack = stack->next;
		stack = stack->next;
	}
	sa(list, NULL);
	if (b > a)
		return (true);
	return (false);
}

void	solve_first(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	/*WHILE stack A has elements with "false" value in "Keep in Stack A" field
      IF sa (swap a) is needed
            perform sa (swap a) command
            update markup
      ELSE IF head element of stack A has "false" value in "Keep in Stack A" field
            perform pb (push b) command
      ELSE
            perform ra (rotate a) command*/
	t_stack	*stack_a;

	stack_a = a->head;
	while (check_align(a, true) == false)
	{
		if (sa_needed == true)
			sa(a, command, true);
		else if (a->head->keep_in == false)
			pb(a, b, command);
		else
			ra(a, command);
	}
}

void	solve_a2b(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	t_bool	enough;
	t_stack	*stack;

	enough = false;
	stack = a->head;
	while ()
	{
		
	}
}