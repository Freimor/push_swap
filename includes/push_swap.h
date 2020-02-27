/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:52:42 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/25 16:51:07 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <../libft/includes/libft.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	false,
	true
}	t_bool;

typedef	struct	s_comand
{
	char			*name;
	struct s_comand	*next;
}				t_comand;

typedef	struct	s_list_comand
{
	int				size;
	struct s_comand	*head;
}				t_list_comand;

typedef	struct	s_stack
{
	int				num;
	int				index;
	t_bool			keep_in;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_list_stack
{
	int				size;
	struct s_stack	*head;
}				t_list_stack;
#endif // !PUSH_SWAP_H