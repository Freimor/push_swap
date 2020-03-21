/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/03/21 16:04:07 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list_stack	*form_first_list(t_list_stack *list, int num)
{
	t_stack *stack;

	if (list == NULL)
	{
		list = (t_list_stack *)malloc(sizeof(t_list_stack));
		list->head = NULL;
	}
	if (list->head == NULL)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		stack->num = num;
		stack->next = NULL;
		stack->index = -1;
		list->head = stack;
	}
	else
	{
		stack = list->head;
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = (t_stack *)malloc(sizeof(t_stack));
		stack->next->num = num;
		stack->next->next = NULL;
		stack->next->index = -1;
	}
	return(list);
}

int	main(int ac, char **arg)
{
	t_list_stack	*list;
	t_list_stack	*new_list;
	t_list_stack	*index_list;
	int	i;

	i = 1;
	list = NULL;
	if (ac < 2)
	{
		ft_putstr("Error input\n");
		return (0);
	}
	while (i < ac)
	{
		if (input_check_number(arg[i]) == false)
		{
			ft_putstr("Error on args\n");
			return(0);
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		list = form_first_list(list, ft_atoi(arg[i]));
		i++;
	}
	if (list_checkduplicate(list) == false)
	{
		ft_putstr("Error dup\n");
		return (0);
	}
//	print_list(list, true, true);
	list_indexing(list);
	// index_list = list_sort_ascending(list);
	// set_index(index_list);
	// list_apply_index(list, index_list);
	
	// if (rb_or_rrb(list, 2) == true)
	// 	printf("ra");
	// else
	// 	printf("rra");
	solve_1(list);
	return (0);
}