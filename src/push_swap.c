/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/04/06 11:13:25 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **arg)
{
	t_list_stack	*numbers;
	t_list_command	*commands;

	if ((numbers = input_fabrication(ac, arg)) == NULL)
		crash("Error\n");
	if ((commands = push_swap(numbers)) == NULL)
		crash("Error\n");
	print_commands(commands);
	command_list_delete(commands);
	return (0);
}