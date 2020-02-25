/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:17:54 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/25 17:01:23 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		main(int argc, char **argv)
{
	int		i;
	t_stack *stack_a;
	
	
	i = 1;
	while (argc - 1 > 0)
	{
		if (argv[i] && (argv[i][0] > '0' && argv[i][0] < '9') && argv[i][1] == '\0')
			add(stack_a, argv[i][0]);
		else
			teminated("Error");
		i++;
		argc--;
	}
	return(0);
}