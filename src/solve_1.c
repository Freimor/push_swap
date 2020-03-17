/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:55:53 by freimor           #+#    #+#             */
/*   Updated: 2020/03/16 19:32:50 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		mantiss(t_list_stack *list)
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

t_bool		check_listmantiss(t_list_stack *list, int mantiss)
{
	t_stack *stack;

	stack = list->head;
	while (stack != NULL)
	{
		if (stack->index < mantiss)
			return(false);
		stack = stack->next;
	}
	return (true);
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
			sb(b, command);
		else if (a - c < c)
			rrb(b, command);
		else
			rb(b, command);
	}
}

/*void	solve_try_2(t_list_stack *a, t_list_stack *b, t_list_command *command)
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
}*/

void	clean_commands(t_list_stack *b)
{
	t_stack	*stack;

	if (b->head != NULL)
	{
		stack = b->head;
		while (stack != NULL)
		{
			free(stack->comand_list);
			stack->comand_list = NULL;
			stack = stack->next;
		}
	}
}

void	stage_1(t_list_stack *b, int index)			//not debag
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
	free(copy_list);
}

int		find_min_or_max_index(t_list_stack *list, t_bool min)
{
	t_stack		*stack;
	int			perem;
	
	if (list->head)
	{
		stack = list->head->next;
		perem = list->head->index;
		while (stack != NULL)
		{
			if (min == true)
			{
				if (stack->index < perem)
					perem = stack->index;
			}
			else
			{
				if (stack->index > perem)
					perem = stack->index;
			}
			stack = stack->next;
		}
		return (perem);
	}
	else
		return (-1);
}

/*int		find_closest_index(t_list_stack *a, int index)
{
	t_stack		*stack;
	int			min;
	int			max;
	int			temp_min;
	int			temp_max;
	
	if (a->head)
	{
		stack = a->head;
		min = find_min_or_max(a, true);
		//max = find_min_or_max(a, false);

		temp_min = find_min_or_max(a, false);
		temp_max = find_min_or_max(a, false);
		while (stack != NULL)
		{
			if (stack->index < index && ft_abs(index - stack->index) < temp_min)
			{
				min = stack->index;
				temp_min = ft_abs(index - stack->index);
			}
			else if (stack->index > index && ft_abs(index - stack->index) < temp_max)
			{
				max = stack->index;
				temp_max = ft_abs(index - stack->index);
			}
			stack = stack->next;
		}
		if (temp_min < temp_max)
			return (min);
		else
			return (max);
	}
	return (-1);
}*/

int		find_closest_index(t_list_stack *a, int index)				//not debag
{
	t_stack		*stack;
	int			closest_index;
	int			temp;
	
	if (a->head)
	{
		stack = a->head;
		closest_index = stack->index;
		temp = ft_abs(stack->index - index);
		while (stack != NULL)
		{
			if (ft_abs(stack->index - index) == temp)
			{
				if (closest_index < stack->index)
					closest_index = stack->index;
			}
			else if (ft_abs(stack->index - index) < temp)
			{
				temp = ft_abs(stack->index - index);
				closest_index = stack->index;
			}
			stack = stack->next;
		}
		return(closest_index);
	}
	return (-1);
}

void	stage_2(t_list_stack *a, t_list_stack *b, int index)			//not debag
{
	t_stack			*stack_b;
	t_bool			flag;
	t_list_stack	*copy_list;
	int				closest_index;
	
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
		add_command(stack_b->comand_list, "ra");			///??
		add_command(stack_b->comand_list, "pa");
		add_command(stack_b->comand_list, "rra");
	}
	else
		add_command(stack_b->comand_list, "pa");
	free(copy_list);
}

void	update_stack_comands(t_list_stack *a, t_list_stack *b)
{
	t_stack			*stack;

	stack = b->head;
	clean_commands(b);
	printf("after clear\n");
	while (stack != NULL)
	{
		if (stack->comand_list == NULL)
		{
			stack->comand_list = (t_list_command *)malloc(sizeof(t_list_command));
			stack->comand_list->head = NULL;
		}
		stage_1(b, stack->index);
		stage_2(a, b, stack->index);
		printf("A:\n");
		print_list(a, true);
		printf("B:\n");
		print_list(b, true);
		print_commands(stack->comand_list);
		printf("-------\n");
		stack = stack->next;
	}
}
void		solve_after_presort(t_list_stack *a, t_list_command *command)			//rabotaet ispravno
{
	if (list_len(a) == 2)
	{
		if (a->head == a->head->next + 1)
			sa(a, command);
	}
	else if (list_len(a) == 3)
	{
		while (check_align(a) == false)
		{
			if ((a->head->index == a->head->next->index + 2
			&& a->head->index == a->head->next->next->index + 1) ||
			(a->head->index + 2 == a->head->next->index
			&& a->head->index + 1 == a->head->next->next->index))
				ra(a, command);
			else if (a->head->index + 1 == a->head->next->index
			&& a->head->index == a->head->next->next->index + 1)
				rra(a, command);
			else if ((a->head->index == a->head->next->index + 1
			&& a->head->index == a->head->next->next->index + 2) ||
			(a->head->index == a->head->next->index + 1
			&& a->head->index + 1 == a->head->next->next->index))
				sa(a, command);
		}
	}
}

void		drops(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	int		mantissa;
	t_bool	flag;
	t_stack	*stack_bottom;

	stack_bottom = a->head;
	while (stack_bottom->next != NULL)
			stack_bottom = stack_bottom->next;
	mantissa = mantiss(a);
	flag = false;
	while (flag == false)
	{
		if (a->head == stack_bottom)
			flag = true;
		if (a->head->index < mantissa)
			pb(a, b, command);
		else
			ra(a, command);
	}
}

void		presort_a(t_list_stack *a, t_list_stack *b, t_list_command *command)
{
	while (list_len(a) > 3)
	{
		drops(a, b, command);
	}
	solve_after_presort(a, command);
}

/*void	add_command_to_main_list(t_list_command *add, t_list_command *main)
{
	t_command	*src;
	t_command	*dst;
	
	dst = main->head;
	src = add->head;
	while (dst->next != NULL)
		dst = dst->next;
	while (src != NULL)
	{
		dst->next = (t_command *)malloc(sizeof(t_command));
		dst->name = ft_strcpy(dst->name, src->name);
		dst->next = NULL;
		src = src->next;
	}
}*/

void	exec_command_list(int index, t_list_command *command, t_list_stack *a, t_list_stack *b)
{
	t_stack		*stack_b;
	t_command	*commands;

	stack_b = b->head;
	while (stack_b->index != index)
		stack_b = stack_b->next;
	commands = stack_b->comand_list->head;
	while (commands != NULL)
	{
		if (ft_strequ("sa", commands->name) == 1)
			sa(a, command);
		else if (ft_strequ("pa", commands->name) == 1)
			pa(a, b, command);
		else if (ft_strequ("ra", commands->name) == 1)
			ra(a, command);
		else if (ft_strequ("rra", commands->name) == 1)
			rra(a, command);
		else if (ft_strequ("sb", commands->name) == 1)
			sb(a, command);
		else if (ft_strequ("pb", commands->name) == 1)
			pb(a, b, command);
		else if (ft_strequ("rb", commands->name) == 1)
			rb(a, command);
		else if (ft_strequ("rrb", commands->name) == 1)
			rrb(a, command);
		else if (ft_strequ("ss", commands->name) == 1)
			ss(a, b, command);
		else if (ft_strequ("rr", commands->name) == 1)
			rr(a, b, command);
		else if (ft_strequ("rrr", commands->name) == 1)
			rrr(a, b, command);
		commands = commands->next;
	}
}

/*void	double_command_replace(t_stack *stack, int array[])
{
	t_command		*command;
	int				i;

	i = 0;
	command = stack->comand_list->head;
	while (command != NULL)
	{
		i = ft_abs(array[0] - array[2]);
		
	}
}*/

void	double_command_update(t_stack *stack)
{
	t_command		*command;
	int				array[4];

	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
	
	command = stack->comand_list->head;
	while (command != NULL)
	{
		if (ft_strequ(command->name, "ra") == 1)
			array[0]++;
		else if (ft_strequ(command->name, "rra") == 1)
			array[1]++;
		else if (ft_strequ(command->name, "rb") == 1)
			array[2]++;
		else if (ft_strequ(command->name, "rrb") == 1)
			array[3]++;
		command = command->next;
	}
	//double_command_replace(stack, array);
}

/*void	exec_command(char	*str, t_list_command *command, t_list_stack *a, t_list_stack *b)
{
	if (ft_strequ("sa", str) == 1)
		sa(a, command);
	else if (ft_strequ("pa", str) == 1)
		pa(a, b, command);
	else if (ft_strequ("ra", str) == 1)
		ra(a, command);
	else if (ft_strequ("rra", str) == 1)
		rra(a, command);
	else if (ft_strequ("sb", str) == 1)
		sb(a, command);
	else if (ft_strequ("pb", str) == 1)
		pb(a, b, command);
	else if (ft_strequ("rb", str) == 1)
		rb(a, command);
	else if (ft_strequ("rrb", str) == 1)
		rrb(a, command);
	else if (ft_strequ("ss", str) == 1)
		ss(a, b, command);
	else if (ft_strequ("rr", str) == 1)
		rr(a, b, command);
	else if (ft_strequ("rrr", str) == 1)
		rrr(a, b, command);
}*/

void	push_minb2a(t_list_stack *a, t_list_stack *b, t_list_command *command)
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
	printf("%d : %d <------\n", save->num, save->index);
	
	while (b->head != save)				//kostil
	{
		rb(b, NULL);
	}
	
	//double_command_update(save);
	/*comm = save->comand_list->head;
	while (comm != NULL)
	{
		exec_command(comm->name, command, a, b);
		comm = comm->next;
	}*/
	exec_command_list(save->index, command, a ,b);			//!!!!!!!!!!!!!!!!!!!!!!!!
}

void	zero_to_head(t_list_stack *a, t_list_command *command)
{
	t_bool	flag;
	
	flag = rb_or_rrb(a, 0);
	while (a->head->index != 0)
	{
		if (flag == true)
			ra(a, command);
		else
			rra(a, command);
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
	print_list(a, true);
	ft_putstr("++++++++++\n");
	//print_commands(command);
	presort_a(a, b, command);
	while (b->head != NULL)
	{
		update_stack_comands(a, b);
		push_minb2a(a, b, command);
	//	aligned(a, command, true);
	}
	zero_to_head(a, command);
	ft_putstr("----------\n");
	print_list(a, true);
	ft_putstr("----------\n");
	print_list(b, true);
	printf("%d\n", command->size);
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