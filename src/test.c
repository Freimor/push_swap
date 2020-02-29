/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:17:02 by freimor           #+#    #+#             */
/*   Updated: 2020/02/29 14:11:48 by freimor          ###   ########.fr       */
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

void	solve_first(t_list_stack *a, t_list_stack *b, t_list_comand *command)
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
		if (sa_needed == true)
			sa(a, command, true);
		else if (a->head->keep_in == false)
			pb(a, b, command);
		else
			ra(a, command);
	}
}

void	solve_second(t_list_stack *a, t_list_stack *b, t_list_comand *command)
{
	/*WHILE stack B is not empty
      choose element in stack B for moving to stack A
      move stack A and stack B to prepare them for pa (push a) with chosen element
      perform pa (push a) command*/
	  while (b->head != NULL)
	  {
		  
	  }
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
	markup_index(list);
	//printf("\n");
	//print_stack(list->head);
	//printf("\n");
	//if (sa_needed(list) == true)
	//	printf("true\n");
	//else
	//	printf("false\n");
	print_stack(list->head);
	ra(list, NULL);
	printf("\n");
	print_stack(list->head);
	return (0);
}