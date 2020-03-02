/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freimor <freimor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:52:42 by sskinner          #+#    #+#             */
/*   Updated: 2020/03/01 14:41:37 by freimor          ###   ########.fr       */
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

//list_actions
void			list_add2head(t_list_stack *list, t_stack *node, t_bool copy);
void			list_add2tail(t_list_stack *list, t_stack *node, t_bool copy);
void			list_cut(t_list_stack *list, t_stack *cut_node, t_bool delete);
t_list_stack	*list_copylist(t_list_stack *old);
void			list_deleteall(t_list_stack *list);
t_stack			*stack_copystack(t_stack *stack, t_bool save_next);
t_list_stack	*list_sort_ascending(t_list_stack *list);
void			set_index(t_list_stack *sortlist);
void			list_apply_index(t_list_stack *dst, t_list_stack *src);


//solve_actions
void			markup_index(t_list_stack *list);

//command actions
void			add_comand(t_list_comand *list_comands, char *comand);
t_bool			sa_needed(t_list_stack *list);


//commands
void			sa(t_list_stack *a, t_list_comand *list_command, t_bool markup);
void			pa(t_list_stack *a, t_list_stack *b, t_list_comand *list_command);
void			ra(t_list_stack *a, t_list_comand *list_command);
void			rra(t_list_stack *a, t_list_comand *list_command);
void			sb(t_list_stack *b, t_list_comand *list_command, t_bool markup);
void			pb(t_list_stack *a, t_list_stack *b, t_list_comand *list_command);
void			rb(t_list_stack *b, t_list_comand *list_command);
void			rrb(t_list_stack *b, t_list_comand *list_command);
void			ss(t_list_stack *a, t_list_stack *b, t_list_stack *list_command);
void			rr(t_list_stack *a, t_list_stack *b, t_list_comand *list_command);
void			rrr(t_list_stack *a, t_list_stack *b, t_list_comand *list_command);


#endif // !PUSH_SWAP_H