/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_algoritm_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 14:40:57 by rick              #+#    #+#             */
/*   Updated: 2020/04/02 17:51:22 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stage_1(t_list_stack *b, int index)			//not debag
{
	t_stack			*stack;
	t_bool			flag;
	t_list_stack	*copy_list;

	flag = false;
	copy_list = list_copylist(b);
	stack = b->head;
	while (stack->index != index)
		stack = stack->next;
	if (rb_or_rrb(b, index) == true)
		flag = true;
	while (copy_list->head->index != stack->index)
	{
		if (flag == true)
			rb(copy_list, stack->comand_list);
		else
			rrb(copy_list, stack->comand_list);
	}
	list_deleteall(copy_list);
}

static t_bool	stage_2(t_list_stack *a, t_list_stack *b, int index)			//not debag
{
	t_stack			*stack_b;
	t_bool			flag;
	t_bool			ret;
	t_list_stack	*copy_list;
	int				closest_index;
	
	ret = false;
	flag = false;
	copy_list = list_copylist(a);
	stack_b = b->head;
	while (stack_b->index != index)
		stack_b = stack_b->next;
	closest_index = find_closest_index(a, index);
	if (rb_or_rrb(a, closest_index) == true)
		flag = true;
	while (copy_list->head->index != closest_index)
	{
		if (flag == true)
			ra(copy_list, stack_b->comand_list);
		else if (flag == false)
			rra(copy_list, stack_b->comand_list);
	}
	if (closest_index < index)
	{
		if (find_command(stack_b->comand_list, "rra") == true)
			command_delete(stack_b->comand_list, "rra");
		else
			command_add(stack_b->comand_list, "ra");			///??
		//command_add(stack_b->comand_list, "rra");
		ret = true;
	}
	command_add(stack_b->comand_list, "pa");
	list_deleteall(copy_list);
	return (ret);
}

static void	update_stack_comands(t_list_stack *a, t_list_stack *b)
{
	t_stack			*stack;
	t_bool			flag;

	stack = b->head;
	clean_commands(b);
	printf("after clear\n");
	while (stack != NULL)
	{
		stage_1(b, stack->index);
		flag = stage_2(a, b, stack->index);
		//command_set_sizes(b);
		//double_command_update(stack, flag);				/// !! ./push_swap 0 1 -4 31 -42 -3 2 41 33 -33 1313 -34 | -33 не на своем месте при double_commands | причем иногда правильно считает
		//видимо эта херня не работает когда появляется фантомный баг
		printf("A:\n");
		print_list(a, true);
		printf("B:\n");
		print_list(b, true);
		print_commands(stack->comand_list);
		printf("-------\n");
		stack = stack->next;
	}
}

static void	push_minb2a(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	t_stack		*stack_b;
	t_stack		*save;
	t_command	*comm;
	int		min;
	
	stack_b = b->head;
	min = stack_b->comand_list->size;
	save = stack_b;
	
	while (stack_b->next != NULL)
	{
		if (stack_b->next->comand_list->size < min)
		{
			save = stack_b->next;
			min = stack_b->next->comand_list->size;
		}
		stack_b = stack_b->next;
	}
	printf("min index %d <------\n", save->index);
	
	/*stack_b = b->head;
	while (stack_b->index != save)
		stack_b = stack_b->next;
	double_command_update(stack_b);*/
	
	exec_command_list(save->comand_list, command, a ,b);
}

void	solve(t_list_stack *a, t_list_command *command)
{
	t_list_stack		*b;
	t_stack				*stack;
	
	b = (t_list_stack *)malloc(sizeof(t_list_stack));
	b->head = NULL;
	print_list(a, true);
	ft_putstr("++++++++++\n");
	solve_first(a, b, command);
	stack = b->head;
	while (stack)
	{
		stack->comand_list = (t_list_command *)malloc(sizeof(t_list_command));
		stack->comand_list->head = NULL;
		stack->comand_list->size = 0;
		stack = stack->next;
	}
	while (b->head != NULL)
	{
		update_stack_comands(a, b);
		push_minb2a(a, b, command);
		print_commands(command);
	}
	zero_to_head(a, command);
	ft_putstr("----------\n");
	print_list(a, true);
	ft_putstr("----------\n");
	print_list(b, true);
	printf("%d\n", command->size);
	list_deleteall(b);
	//print_commands(command);
}

/// дроп по мантиссе до ~3х чисел
/// сорт этих чисел
/// каждому числу из стака b надо найти число команд для добавления в стак а
///    найти число команд rb или rrb 
///    найти число команд ra или rra что бы число в хед по сорту встало
///    + pa
/// найти число из стака b с наименьшим числом команд
/// пушнуть в стак а и обновить все списки команд стака b