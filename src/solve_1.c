/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:55:53 by freimor           #+#    #+#             */
/*   Updated: 2020/03/03 15:00:36 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	check_keepin(t_list_stack *list)
{
	t_stack	*stack;

	stack = list->head;
	while (stack != NULL)
	{
		if (stack->keep_in == false)
			return (false);
		stack = stack->next;
	}
	return (true);
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

void	solve_second(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	/*WHILE stack B is not empty
      choose element in stack B for moving to stack A
      move stack A and stack B to prepare them for pa (push a) with chosen element
      perform pa (push a) command*/
	
	t_stack	*stack_b;

	markup_small(b);
	stack_b = b->head;
	while (check_keepin(b) == false)
	{
		if (sa_needed(b) == true)
			sb(b, command, true);
		if (b->head->keep_in == false)
		{
			if ((a->head->index + 1) == b->head->index)
			{
				ra(a, command);
				pa(a, b, command);
			}
		}
		else
			rb(b, command);
	}
}

t_bool	check_align(t_list_stack *list)
{
	t_stack *stack;

	stack = list->head;
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	aligned(t_list_stack *list,t_list_command *command, t_bool its_a)
{
	t_stack *stack;
	t_bool	flag;

	flag = false;
	stack = list->head;
	while (check_align(list) == false)
	{
		stack = list->head;
		if (stack->index > stack->next->index)
		{
			if (its_a == true)
				sa(list, command, false);
			else
				sb(list, command, false);
		}
		else
		{
			if (its_a == true)
				rra(list, command);
			else
				rrb(list, command);
		}
	}
}

void	solve_1(t_list_stack *a)
{
	t_list_stack		*b;
	t_list_command		*command;

	b = (t_list_stack *)malloc(sizeof(t_list_stack));
	b->head = NULL;
	solve_first(a, b, command);
	//aligned(a, command, true);
	//aligned(b, command, false);
	solve_second(a, b, command);
	ft_putstr("----------\n");
	print_list(a, true, false);
	ft_putstr("----------\n");
	print_list(b, true, false);
}