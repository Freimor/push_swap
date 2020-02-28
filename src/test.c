/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:17:02 by freimor           #+#    #+#             */
/*   Updated: 2020/02/28 17:44:15 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack			*stack_copystack(t_stack *stack, t_bool save_next)
{
	t_stack	*new_stack;
	
	new_stack = (t_stack *)malloc(sizeof(t_stack));
	new_stack->num = stack->num;
	new_stack->index = stack->index;
	new_stack->keep_in = stack->keep_in;
	if (save_next == true)
		new_stack->next = stack->next;
	else
		new_stack->next = NULL;
	return(new_stack);
}

void			list_deleteall(t_list_stack *list)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = list->head;
	while (stack->next != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	free(list);
}

t_list_stack	*list_copylist(t_list_stack *old)
{
	t_stack			*stack;
	t_stack			*new_stack;
	t_list_stack	*new_list;

	stack = old->head;
	new_list = (t_list_stack *)malloc(sizeof(t_list_stack));
	new_stack = (t_stack *)malloc(sizeof(t_stack));
	new_list->head = new_stack;
	new_list->size = old->size;
	new_stack->num = stack->num;
	new_stack->index = stack->index;
	new_stack->keep_in = stack->keep_in;
	while (stack->next != NULL)
	{
		new_stack->next = (t_stack *)malloc(sizeof(t_stack));
		new_stack = new_stack->next;
		stack = stack->next;
		new_stack->num = stack->num;
		new_stack->index = stack->index;
		new_stack->keep_in = stack->keep_in;
	}
	return (new_list);
}

int				print_stack(t_stack *stack)
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

void	list_add2head(t_list_stack *list, t_stack *new_node, t_bool copy)
{
	t_stack	*stack;
	t_stack *temp;

	if (copy == false)
	{
		stack = list->head;
		list->head = new_node;
		new_node->next = stack;
	}
	else
	{
		temp = stack_copystack(new_node, false);
		stack = list->head;
		list->head = temp;
		temp->next = stack;
	}
}

void	list_add2tail(t_list_stack *list, t_stack *new_node)
{
	t_stack	*stack;

	stack = list->head;
	while(stack->next != NULL)
		stack = stack->next;
	stack->next = new_node;
}

void	list_cut(t_list_stack *list, t_stack *cut_node, t_bool delete)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = list->head;
	if (stack == cut_node)
		list->head = stack->next;
	else
	{
		while (stack->next != cut_node)
			stack = stack->next;
		temp = stack->next->next;
		stack->next = temp;
	}
	if (delete == true)
		free(cut_node);
}

void			set_index(t_list_stack *sortlist)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = sortlist->head;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

t_list_stack	*list_sort_ascending(t_list_stack *list)
{
	t_list_stack	*new_list;
	t_stack			*new_stack;
	t_stack			*temp;
	t_bool			flag_sort;

	flag_sort = false;
	new_list = list_copylist(list);
	new_stack = new_list->head;
	while (flag_sort == false)
	{
		flag_sort = true;
		while (new_stack->next != NULL)
		{
			if (new_stack->num > new_stack->next->num)
			{
				temp = stack_copystack(new_stack->next, false);
				list_cut(new_list, new_stack->next, true);
				list_add2head(new_list, temp, true);
				free(temp);
				flag_sort = false;
				new_stack = new_list->head;
				break ;
			}
			new_stack = new_stack->next;
		}
	}
	return(new_list);
}

void	list_apply_index(t_list_stack *dst, t_list_stack *src)
{
	t_stack	*src_stack;
	t_stack	*dst_stack;

	dst_stack = dst->head;
	src_stack = src->head;
	while (dst_stack!= NULL)
	{
		while (dst_stack->num != src_stack->num)
			src_stack = src_stack->next;
		dst_stack->index = src_stack->index;
		dst_stack = dst_stack->next;
		src_stack = src->head;
	}
}

void	markup_index(t_list_stack *list)
{
	t_list_stack	*index_list;
	t_stack			*old_stack;
	t_stack			*index_stack;
	int				index;

	index_list = list_sort_ascending(list);
	set_index(index_list);
	list_apply_index(list, index_list);
	index_stack = index_list->head;
	old_stack = list->head;
	old_stack->keep_in = true;
	index = old_stack->index;
	while (old_stack->next != NULL)
	{
		if (old_stack->next->index == (index + 1))
		{
			old_stack->next->keep_in = true;
			index = old_stack->next->index;
		}
		else
			old_stack->next->keep_in = false;
		old_stack = old_stack->next;
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
	print_stack(list->head);
	markup_index(list);
	printf("\n");
	print_stack(list->head);
	return (0);
}