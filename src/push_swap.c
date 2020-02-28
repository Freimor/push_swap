/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/28 12:43:41 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool		check_index_is_set(t_list_stack *list)
{
	t_stack *stack;

	while (stack->next != NULL)
	{
		if (stack->index == -1)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int			find_min_stack(t_list_stack *list, int min, t_bool is_first)
{
	t_stack *stack;
	t_bool	index_full;
	int		new_min;

	index_full = false;
	stack = list->head;
	if (is_first == true)
	{
		min = stack->num;
		stack = stack->next;
	}
	else
	{
		if (stack->num == min)
			stack = stack->next;
		new_min = stack->num;
		stack = stack->next;
		while (stack->next != NULL)
		{
			if (stack->num == min)
				stack = stack->next;
			if (stack->num < new_min)
				new_min = stack->num;
		}
	}
	return (is_first == true ? min : new_min);
}

int				set_index(t_list_stack *list)
{
	t_stack *stack;
	int		min;
	t_bool	index_full;

	index_full = false;
	stack = list->head;
	min = find_min_stack(list, 0, true);
	while (stack->next != NULL)
	{
		if (stack->num == min)
		{
			stack->index = 0;
			break ;
		}
		stack = stack->next;
	}
	stack = list->head;
	while (check_index_is_set(list) != true)
	{
		
	}
}

int				print_stack(t_list_stack *list)
{
	t_stack	*new;

	new = list->head;
	while (new != NULL)
	{
		printf("%d\n", new->num);
		new = new->next;
	}
	return(0);
}

t_list_stack*	add(t_stack *a, t_list_stack *list, char *str)
{
	t_stack *new;

	a = (t_stack *)malloc(sizeof(t_stack));
	a->num = ft_atoi(str);
	a->index = -1;
	a->next = NULL;
	if (list->head == NULL)
	{
		list->head = a;
		list->size = 1;
	}
	else
	{
		new = list->head;
		while (new->next != NULL)
			new = new->next;
		new->next = a;
		list->size++;
	}
	return(list);
}

int		checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return(0);
}

int		main(int argc, char **argv)
{
	int				i;
	t_stack			*stack_a;
	t_list_stack	*stack_list;
	
	stack_list = (t_list_stack *)malloc(sizeof(t_list_stack));
	stack_list->size = 0;
	stack_list->head = NULL;
	i = 1;
	while (argc - 1 > 0)///херня
	{
		if (checker(argv[i]) == 0)
			stack_list = add(stack_a, stack_list, &argv[i][0]);
		else
		{
			ft_putstr("Error");
			return(-1);
		}
		i++;
		argc--;
	}
	print_stack(stack_list);
	return(0);
}