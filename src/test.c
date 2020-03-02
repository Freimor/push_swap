/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:17:02 by freimor           #+#    #+#             */
/*   Updated: 2020/03/01 14:29:34 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		print_stack(t_stack *stack)
{
	int	keepin;
	while (stack != NULL)
	{
		if (stack->keep_in == true)
			keepin = 1;
		else
			keepin = 0;
		printf("%d  %d  %d\n", stack->num, stack->index, keepin);
		stack = stack->next;
	}
	return(0);
}


int	main(void)
{
	t_list_stack	*list;
	t_list_stack	*new_list;
	t_stack			*one;
	t_stack			*two;
	t_stack			*three;
	t_stack			*new;
	t_list_comand	*commands;

	three = (t_stack *)malloc(sizeof(t_stack));
	three->num = 56;
	three->index = -1;
	three->next = NULL;

	two = (t_stack *)malloc(sizeof(t_stack));
	two->num = 11;
	two->index = -1;
	two->next = three;

	one = (t_stack *)malloc(sizeof(t_stack));
	one->num = 21;
	one->index = -1;
	one->next = two;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->num = -1;
	new->index = -1;
	new->next = NULL;

	list = (t_list_stack *)malloc(sizeof(t_list_stack));
	list->head = one;

	list_add2tail(list, new, false);
	print_stack(list->head);
	printf("\n");
	new_list = list_sort_ascending(list);
	set_index(new_list);
	list_apply_index(list, new_list);
	rra(list, NULL);
	rra(list, NULL);
	print_stack(list->head);
	//ra(list, NULL);
	return (0);
}