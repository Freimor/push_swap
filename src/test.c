/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:17:02 by freimor           #+#    #+#             */
/*   Updated: 2020/03/23 21:58:51 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	check_mark(t_list_stack *list)
{
	t_stack	*stack;

	stack = list->head;
	while (stack != NULL)
	{
		if (stack->flag == false)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_bool	rb_or_rrb(t_list_stack *b, int index)
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
	return (a - c >= c ? true : false);
}

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return (0);
		i++;
	}
	return (1);
}

t_bool	check_align(t_list_stack *list, t_bool rigor)
{
	t_stack *stack;

	stack = list->head;
	if (rigor == false)
	{
		while (stack->next != NULL)
		{
			if (stack->index > stack->next->index)
				return (false);
			stack = stack->next;
		}
	}
	else
	{
		while(stack->next != NULL)
		{
			if (stack->index + 1 != stack->next->index)
				return (false);
			stack = stack->next;
		}
	}
	return (true);
}

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
	while (stack->next != NULL)
	{
		if (stack->next->index == temp + 1)
		{
			temp++;
			b++;
		}
		stack = stack->next;
	}
	sa(list, NULL);
	if (b > a)
		return (true);
	return (false);
}

/*void	solve_first(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	while (check_align(a, true) == false)
	{
		if (sa_needed(a) == true)
			sa(a, command);
		else if (a->head->index + 1 != a->head->next->index)
		{
			ra(a, command);
			pb(a, b, command);
		}
		else
			ra(a, command);
	}
}*/
void	attribute_apply(t_list_stack *list, t_list_stack *temp)
{
	t_stack *stack;
	t_stack *temp_stack;

	stack = list->head;
	while (stack != NULL)
	{
		temp_stack = temp->head;
		while (temp_stack != NULL)
		{
			if (temp_stack->index == stack->index)
				stack->flag = temp_stack->flag;
			temp_stack = temp_stack->next;
		}
		stack = stack->next;
	}
}

int		sort_combo(t_list_stack *list, int index, t_bool mark)
{
	t_list_stack *temp_list;
	int		count;
	int		temp;

	temp_list = list_copylist(list);
	count = 1;
	while (temp_list->head->index != index)
		ra(temp_list, NULL);
	temp = temp_list->head->index;
	temp_list->head->flag = true;
	ra(temp_list, NULL);
	while (temp_list->head->index != index)
	{
		if (temp_list->head->next->index == temp + 1)
		{
			sa(temp_list, NULL);
			temp_list->head->flag = true;
			ra(temp_list, NULL);
			count++;
			temp++;
		}
		else if (temp_list->head->index == temp + 1)
		{
			temp_list->head->flag = true;
			ra(temp_list, NULL);
			count++;
			temp++;
		}
		else
			ra(temp_list, NULL);
	}
	if (mark == true)
		attribute_apply(list, temp_list);
	list_deleteall(temp_list);
	return (count);
}

/*int		sort_combo(t_list_stack *list, int index, t_bool mark)
{
	t_stack *stack;
	t_stack	*iter;
	int		count;
	int		temp;

	count = 1;
	stack = list->head;
	while (stack->index != index)
		stack = stack->next;
	if (stack->next == NULL)
		iter = list->head;
	else
		iter = stack->next;
	temp = stack->index;
	if (mark == true)
		stack->flag = true;
	while (iter != stack)
	{	
		if (iter->index == temp + 1)
		{
			if (mark == true)
				iter->flag = true;
			count++;
			temp++;
		}
		if (iter->next == NULL)
			iter = list->head;
		else
			iter = iter->next;
	}
	return (count);
}*/

int		check_where_start(t_list_stack *list)
{
	t_stack	*stack;
	int		index;
	int		max_sort_elem;

	stack = list->head;
	max_sort_elem = 0;
	while (stack != NULL)
	{
		if (sort_combo(list, stack->index, false) > max_sort_elem)
		{
			max_sort_elem = sort_combo(list, stack->index, false);
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
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
	int		start_index;
	t_bool	flag;
	
	start_index = check_where_start(a);
	sort_combo(a, start_index, true);
	flag = rb_or_rrb(a, start_index);
	while (a->head->index != start_index)
	{
		if (flag == true)
			ra(a, command);
		else
			rra(a, command);
	}
	while (check_align(a, true) == false)
	{
		if (a->head->next->index + 1 == a->head->index && a->head->next->flag == true)
			sa(a, command);
		else if (a->head->flag == true)
			ra(a, command);
		else
			pb(a, b, command);
	}
}

//gcc -g test.c ../includes/push_swap.h operation_list_a.c operation_list_b.c list_actions.c list_additionals.c command_actions.c

int	main(void)
{
	t_list_stack	*list;
	t_list_stack	*new_list;
	t_stack			*one;
	t_stack			*two;
	t_stack			*three;
	t_stack			*four;
	t_stack			*five;
	t_stack			*six;
	t_stack			*seven;
	t_list_command	*commands;

	seven = (t_stack *)malloc(sizeof(t_stack));
	seven->num = 6;
	seven->index = 5;
	seven->flag = false;
	seven->next = NULL;
	
	six = (t_stack *)malloc(sizeof(t_stack));
	six->num = -11;
	six->index = 0;
	six->flag = false;
	six->next = seven;
	
	five = (t_stack *)malloc(sizeof(t_stack));
	five->num = -7;
	five->index = 1;
	five->flag = false;
	five->next = six;
	
	four = (t_stack *)malloc(sizeof(t_stack));
	four->num = 11;
	four->index = 6;
	four->flag = false;
	four->next = five;
	
	three = (t_stack *)malloc(sizeof(t_stack));
	three->num = 5;
	three->index = 4;
	three->flag = false;
	three->next = four;

	two = (t_stack *)malloc(sizeof(t_stack));
	two->num = -3;
	two->index = 2;
	two->flag = false;
	two->next = three;

	one = (t_stack *)malloc(sizeof(t_stack));
	one->num = 0;
	one->index = 3;
	one->flag = false;
	one->next = two;

	list = (t_list_stack *)malloc(sizeof(t_list_stack));
	list->head = one;
	
	new_list = (t_list_stack *)malloc(sizeof(t_list_stack));
	new_list->head = NULL;
	
	commands = (t_list_command *)malloc(sizeof(t_list_command));
	commands->head = NULL;
	
	solve_first(list, new_list, commands);
	
	while (list->head != NULL)
	{
		printf("%d : %d\n", list->head->num, list->head->index);
		list->head = list->head->next;
	}
	printf("-=-=-=-=-=-=\n");
	while (new_list->head != NULL)
	{
		printf("%d : %d\n", new_list->head->num, new_list->head->index);
		new_list->head = new_list->head->next;
	}
	printf("||||||||||||\n");
	while (commands->head != NULL)
	{
		printf("%s\n", commands->head->name);
		commands->head = commands->head->next;
	}
}