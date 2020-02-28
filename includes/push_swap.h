/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:52:42 by sskinner          #+#    #+#             */
/*   Updated: 2020/02/28 17:31:42 by freimor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"
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

void			list_add2head(t_list_stack *list, t_stack *new_node, t_bool copy);
void			list_add2tail(t_list_stack *list, t_stack *new_node);
void			list_cut(t_list_stack *list, t_stack *cut_node, t_bool delete);
t_list_stack	*list_copylist(t_list_stack *old);
void			list_deleteall(t_list_stack *list);
t_stack			*stack_copystack(t_stack *stack, t_bool save_next);


#endif // !PUSH_SWAP_H