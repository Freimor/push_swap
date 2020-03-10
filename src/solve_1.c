/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:55:53 by freimor           #+#    #+#             */
/*   Updated: 2020/03/10 14:17:55 by sskinner         ###   ########.fr       */
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
	t_stack *stack_bottom;
	t_bool	flag;

	flag = false;
	while (check_align(list) == false)
	{
		stack_bottom = list->head;
		while (stack_bottom->next != NULL)
			stack_bottom = stack_bottom->next;
		if (list->head->index > list->head->next->index && list->head->next->index != 0)
		{
			if (its_a == true)
				sa(list, command, false);
			else
				sb(list, command, false);
		}
		else if ((stack_bottom->index + 1) == list->head->index)
		{
			if (its_a == true)
				rra(list, command);
			else
				rrb(list, command);
		}
		else
		{
			if (its_a == true)
				ra(list, command);
			else
				rb(list, command);
		}
	}
}

void	solve_first(t_list_stack *a, t_list_stack *b, t_list_command *command, t_bool first)
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
	if (first == true)
		markup(a, true);
	else
		markup(a, false);
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
	t_stack *stack_bottom;

	//markup(b, false);
	stack_b = b->head;
	//aligned(b, command, false);
	while (b->head != NULL)
	{
		stack_bottom = b->head;
		while (stack_bottom->next != NULL)
			stack_bottom = stack_bottom->next;
		if ((a->head->index + 1) == b->head->index)
		{
			ra(a, command);
			pa(a, b, command);
		}
/*		else if ((stack_bottom->index + 1) == a->head->index)
		{
			rrb(b, command);
			pa(a, b, command);
		}*/
		else
			ra(a, command);
	}
}

int		mantiss(t_list_stack *list) //offset??
{
	int		summ;
	int		i;
	t_stack	*stack;

	summ = 0;
	i = 0;
	stack = list->head;
	while (stack != NULL)
	{
		i++;
		summ += stack->index;
		stack = stack->next;
	}
	return (summ / i);
}

int		list_len(t_list_stack *list)
{
	int		len;
	t_stack *stack;

	len = 0;
	stack = list->head;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void		push2b(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int		mantissa;
	t_stack	*stack;

	if (list_len(a) < 3)
		aligned(a, command, true);
	else
	{
		while (list_len(a) > 3)
		{
			mantissa = mantiss(a);
			stack = a->head;
			while (stack != NULL)
			{
				if (stack->index > mantissa)
					pb(a, b, command);
				if (stack->index <= mantissa)
					ra(a, command);
				stack = stack->next;
			}
		}
	}
	aligned(a, command, true);
}

t_bool		check_listmantiss(t_list_stack *list, int mantiss, t_bool its_a)
{
	t_stack *stack;

	stack = list->head;
	while (stack != NULL)
	{
		if ((its_a == true && stack->index > mantiss)
		|| (its_a == false && stack->index < mantiss))
			return(false);
		stack = stack->next;
	}
	return (true);
}

void		drops_a2b(t_list_stack *a, t_list_stack *b, t_list_command *command, t_bool its_a)
{
	int		mantissa;
	t_list_stack *list;

	if (its_a == true)
		list = a;
	else
		list = b;
	mantissa = mantiss(list);
	while (check_listmantiss(list, mantissa, true) == false)
	{
		if (list->head->index > mantissa)
		{
			if (its_a == true)
				pb(a, b, command);
			else
				pa(a, b, command);
		}
		else
		{
			if (its_a == true)
				ra(a, command);
			else
				rb (b, command);
		}
	}
}

void		drops_b2a(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int		mantissa;

	mantissa = mantiss(b);
	while (check_listmantiss(b, mantissa, false) == false)
	{
		if (b->head->index < mantissa)
			pa(a, b, command);
		else
			rb (b, command);
	}
}

void		solve_try_1(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	while (list_len(a) > 3)
		drops_a2b(a, b, command, true);
	aligned(a, command, true);
	drops_b2a(a, b, command);
}

t_stack		*find_stack(t_list_stack *list, int index)
{
	t_stack *stack;

	if (list != NULL && list->head != NULL)
	{
		stack = list->head;
		while (stack != NULL)
		{
			if (stack->index == index)
				return (stack);
			stack = stack->next;
		}
	}
	return (NULL);
}

void	targetstack2head_b(t_list_stack *b, t_list_command *command,  int index)
{
	t_stack	*stack;
	int		a;
	int		c;
	
	a = 0;
	stack = b->head;
	while (stack != NULL)
	{
		a++;
		if (stack->index == index)
			c = a;											////// a->5  b->3  
		stack = stack->next;
	}
	while (b->head->index != index)
	{
		if (b->head->next->index == index)
			sb(b, command, false);
		else if (a - c < c)
			rrb(b, command);
		else
			rb(b, command);
	}
}

void	solve_try_2(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int	save_index;
	
	save_index = -1;
	ra(a, command);
	while (check_align(a) == false || b->head != NULL)						///add rule swap maybe??
	{
		if (a->head->next->index == save_index + 1)
		{
			sa(a, command, false);
			save_index = a->head->index;
			ra(a, command);
		}
		else if (a->head->index == (save_index + 1))
		{
			save_index = a->head->index;
			ra(a, command);
		}
		else if ((b->head != NULL) && (find_stack(b, save_index + 1) != NULL))
		{
			targetstack2head_b(b, command, save_index + 1);
			pa(a, b, command);
			save_index = a->head->index;
			ra(a, command);
		}
		else
		{
			if (a->head->index > save_index + 1)
				pb(a, b, command);
			else
				rra(a, command);
		}
	}
}

void	solve_1(t_list_stack *a)
{
	t_list_stack		*b;
	t_list_command		*command;

	b = (t_list_stack *)malloc(sizeof(t_list_stack));
	command = (t_list_command *)malloc(sizeof(t_list_command));
	b->head = NULL;
	command->head = NULL;
	command->size = 0;
//	solve_first(a, b, command, true);
//	aligned(a, command, true);
	//aligned(b, command, false);
//	if (b->head != NULL)
//		solve_second(a, b, command);
//	aligned(a, command, true);
	print_list(a, true, false);
	//printf("%d\n", mantiss(a));
	solve_try_2(a, b, command);
	ft_putstr("++++++++++\n");
	print_commands(command);
	ft_putstr("----------\n");
	print_list(a, true, false);
	ft_putstr("----------\n");
	print_list(b, true, false);
	printf("%d\n", command->size);
}