/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:17:02 by freimor           #+#    #+#             */
/*   Updated: 2020/02/28 20:36:42 by freimor          ###   ########.fr       */
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

	list_add2tail(list, new);
	markup_index(list);
	printf("\n");
	print_stack(list->head);
	printf("\n");
	if (sa_needed(list) == true)
		printf("true\n");
	else
		printf("false\n");
	print_stack(list->head);
	ra(list, NULL);
	printf("\n");
	print_stack(list->head);
	return (0);
}