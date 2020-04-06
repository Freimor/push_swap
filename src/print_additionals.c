/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_additionals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:16:23 by freimor           #+#    #+#             */
/*   Updated: 2020/04/05 21:11:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print_check_lennum(t_list_stack *list, t_bool num_or_in)
{
	int		len;
	char	*str;
	int		i;
	t_stack	*stack;

	stack = list->head;
	len = 0;
	while (stack != NULL)
	{
		i = 0;
		if (num_or_in == true)
			str = ft_itoa(stack->num);
		else
			str = ft_itoa(stack->index);
		while (str[i] != '\0')
			i++;
		if (i > len)
			len = i;
		stack = stack->next;
		free(str);
	}
	return (len);
}

void		print_part(int num, int len)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(num);
	while (str[i] != '\0')
		i++;
	i = len - i;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	ft_putstr(str);
	free(str);
}

void		print_list(t_list_stack *list, t_bool with_index)
{
	t_stack	*stack;
	int		l_num;
	int		l_index;

	stack = list->head;
	l_num = print_check_lennum(list, true);
	l_index = print_check_lennum(list, false);
	
	while (stack != NULL)
	{
		print_part(stack->num, l_num);
		if (with_index == true)
		{
			ft_putstr(" : ");
			print_part(stack->index, l_index);
		}
		ft_putchar('\n');
		stack = stack->next;
	}
}

void	print_commands(t_list_command *command)
{
	t_command *line;
	
	line = command->head;

	while (line != NULL)
	{
		ft_putstr(line->name);
		ft_putchar('\n');
		line = line->next;
	}
}