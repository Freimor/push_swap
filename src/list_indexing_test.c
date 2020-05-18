/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_indexing_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 10:26:15 by rick              #+#    #+#             */
/*   Updated: 2020/05/18 11:04:55 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		list_all_elem_count(t_list_stack *list)
{
	t_stack *stack;
	int		count;

	count = 0;
	stack = list->head;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	list_indexing_test(t_list_stack *list)
{
	int		all_elem;
	t_stack	*stack;
	t_stack	*iter;
	int		i;

	all_elem = list_all_elem_count(list);
	stack = list->head;
	while (stack != NULL)
	{
		i = 0;
		if (stack->next == NULL)
			iter = list->head;
		else
			iter = stack->next;
		while (iter != stack)
		{
			if (iter->num > stack->num)
				i++;
			if (iter->next == NULL)
				iter = list->head;
			else
				iter = iter->next;
		}
		stack->index = all_elem - i - 1;
		stack = stack->next;
	}
}

int		main(void)
{
	t_list_stack 	*list;
	t_stack			*s1;
	t_stack			*s2;
	t_stack			*s3;
	t_stack			*s4;
	
	list = (t_list_stack *)malloc(sizeof(t_list_stack));
	s1 = (t_stack *)malloc(sizeof(t_stack));
	s2 = (t_stack *)malloc(sizeof(t_stack));
	s3 = (t_stack *)malloc(sizeof(t_stack));
	s4 = (t_stack *)malloc(sizeof(t_stack));

	list->head = s1;
	
	s1->comand_list = NULL;
	s1->index = -1;
	s1->next = s2;
	s1->num = 6;

	s2->comand_list = NULL;
	s2->index = -1;
	s2->next = s3;
	s2->num = -1;

	s3->comand_list = NULL;
	s3->index = -1;
	s3->next = s4;
	s3->num = 2;

	s4->comand_list = NULL;
	s4->index = -1;
	s4->next = NULL;
	s4->num = -10;

	list_indexing_test(list);
	while (list->head != NULL)
	{
		printf("num-> %d\n", list->head->num);
		printf("index-> %d\n", list->head->index);
		list->head = list->head->next;
	}
	return (0);
}