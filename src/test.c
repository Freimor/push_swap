/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:17:02 by freimor           #+#    #+#             */
/*   Updated: 2020/03/16 16:29:23 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	rb_or_rrb(t_list_stack *b, int index)			//careful check
{
	t_stack	*stack;
	int	a;
	int	c;

	a = 0;
	c = 0;
	stack = b->head;
	while (stack != NULL)
	{
		a++;
		if (stack->index == index)
			c = a;
		stack = stack->next;
	}
	return (a - c > c ? true : false);
}

int	main(void)
{
	t_list_stack	*list;
	t_list_stack	*new_list;
	t_stack			*one;
	t_stack			*two;
	t_stack			*three;
	t_stack			*four;
	t_list_command	*commands;

	four = (t_stack *)malloc(sizeof(t_stack));
	four->num = 4;
	four->index = 3;
	four->next = NULL;
	
	three = (t_stack *)malloc(sizeof(t_stack));
	three->num = 3;
	three->index = 2;
	three->next = four;

	two = (t_stack *)malloc(sizeof(t_stack));
	two->num = 2;
	two->index = 1;
	two->next = three;

	one = (t_stack *)malloc(sizeof(t_stack));
	one->num = 1;
	one->index = 0;
	one->next = two;

	list = (t_list_stack *)malloc(sizeof(t_list_stack));
	list->head = one;
	rb_or_rrb(list, 2);

}